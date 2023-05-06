/** Copyright 2023, Universal Tool Compiler */

/** Info about Substrate material: https://dev.epicgames.com/community/learning/courses/92D/unreal-engine-strata-materials/VXV6/unreal-engine-strata-intro-submitting-feedback */
#include "LiquidShaderComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "PhysicsEngine/BodySetup.h"
#include "UTC_LiquidShaderCSManager.h"

/** Sets default values for this actor's properties*/
ULiquidShaderComponent::ULiquidShaderComponent()
{
	/** Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.*/
	PrimaryComponentTick.bCanEverTick = true;

	WavesIntensity = 1.f;
	WavesRotationSensitivity = .5f;
	WavesOffsetSensitivity = 2.f;
	Viscosity = 2.4f;

	VoxelFactor = 30.f;
	AdaptationSpeedScale = 16.5f;

	GenerateCap = true;
	CleanUpCap = true;
	LiquidAdaptation = true;

	WavesRenderTargetMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/UTC_LiquidShader/Library/MM/Tools/MM_RTWaves.MM_RTWaves'"));
	WavesRenderTargetTexture = LoadObject<UTextureRenderTarget2D>(nullptr, TEXT("/Script/Engine.TextureRenderTarget2D'/UTC_LiquidShader/Library/Textures/RenderTargets/RT_Waves.RT_Waves'"));
	
	LiquidMaterialInstance = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/UTC_LiquidShader/Library/MI/MI_Liquid.MI_Liquid'"));
	CapRenderTargetTexture = LoadObject<UTextureRenderTarget2D>(nullptr, TEXT("/Script/Engine.TextureRenderTarget2D'/UTC_LiquidShader/Library/Textures/RenderTargets/RT_Cap.RT_Cap'"));

	SDF_CapDistanceMaskMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/UTC_LiquidShader/Library/MM/Tools/SDF/MM_SDFCapMask.MM_SDFCapMask'"));
	SDF_CapJumpFloodMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/UTC_LiquidShader/Library/MM/Tools/SDF/MM_SDFCapJumpFlood.MM_SDFCapJumpFlood'"));
}

void ULiquidShaderComponent::RequestStaticMeshComponent_Implementation()
{
	IUTC_LSInterface::RequestStaticMeshComponent_Implementation();
}

#if WITH_EDITOR
void ULiquidShaderComponent::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if(bIsRunning)
	{
		if(bBlueprint)
		{
			if(!GenerateCap)
			{
				RemoveSDF_FromRoot();
			}
		}
		else if(bSMActor)
		{
			CheckLiquidOffsetBounds();
			
			if(GenerateCap)
			{
				if(!IsValid(SDF_CapDistMaskDMI) && !IsValid(SDF_CapJumpFloodDMI))
				{
					GenerateCapDynamicInstances();
				}
			}
			else
			{
				UKismetRenderingLibrary::ClearRenderTarget2D(this, CapRTInstance);
				
				RemoveSDF_FromRoot();
			}
			
			if(LiquidAdaptation && !bLiquidAdaptationIsInit)
			{
				AdaptedLiquidOffset = 0.f;
				InitialLiquidVolume = 0.f;
				
				InitialLiquidOffset = GetLiquidOffset();
				ComputeLiquidVolume(0,true);
			}
		}
	}
};
#endif

/** ---------------------------------------------------------------------- Begin Play ----------------------------------------------------------------------*/
void ULiquidShaderComponent::BeginPlay()
{
	Super::BeginPlay();

	bIsRunning = true;

	if(GetOwner()->GetClass() == AStaticMeshActor::StaticClass())
	{
		bSMActor = true;
	}
	else if (GetOwner()->GetClass()->GetClass() == UBlueprintGeneratedClass::StaticClass())
	{
		bBlueprint = true;
	}
	
	GetLiquidComponents();
	
	GenerateDynamicInstances();
	
	InitSMBounds();

	/** Static mesh minimal setup */
	SMLiquidOwner->GetBodySetup()->bDoubleSidedGeometry = false;
	SMLiquidOwner->bAllowCPUAccess = true;

	InitSections();
	
	GetBubbleParameters(TargetBubbleAmount);

	InitialLiquidOffset = GetLiquidOffset();

	CheckLiquidOffsetBounds();
	
	if(LiquidAdaptation)
	{
		bLiquidAdaptationIsInit = true;
		ComputeLiquidVolume(0,true);
	}
	else
	{
		AdaptedLiquidOffset = GetLiquidOffset();
	}
	
	/** Remove begin play movements */
	PreviousActorLocation = SMComponent->GetComponentLocation();
	PreviousActorUpRotation = FRotationMatrix(SMComponent->GetComponentRotation()).GetScaledAxis(EAxis::Z);
	LiquidShaderDynamicMI->SetScalarParameterValue(TEXT("Bubbles - Main Amount"), 0.f);
}

void ULiquidShaderComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	LiquidShaderDynamicMI->RemoveFromRoot();
	WavesRTDynamicMI->RemoveFromRoot();
	WavesRTInstance->RemoveFromRoot();

	if(IsValid(CapRTInstance))
		CapRTInstance->RemoveFromRoot();
	
	RemoveSDF_FromRoot();
	
	bIsRunning = false;
}

void ULiquidShaderComponent::GenerateDynamicInstances()
{
	/** Create Liquid Shader DMI */
	LiquidShaderDynamicMI = UMaterialInstanceDynamic::Create(LiquidMaterialInstance, this);
	LiquidShaderDynamicMI->AddToRoot();
	
	/** Assign Liquid Shader material instance to the static mesh */
	for (int i = 0; i < SMComponent->GetNumMaterials(); i++)
	{
		UMaterialInterface* CurrentMaterial = SMComponent->GetMaterial(i);
		if(CurrentMaterial == LiquidMaterialInstance )
		{
			/** Replace MI by DMI */
			SMComponent->SetMaterial(i, LiquidShaderDynamicMI);
			MaterialIndices.Add(i);
		}
		else if (IncludeMaterials.Contains(CurrentMaterial))
		{
			MaterialIndices.Add(i);
		}
	}
	
	/** ---------------------------------------------------------------------- Waves ----------------------------------------------------------------------*/
	
	/** Create waves DMI */
	WavesRTDynamicMI = UMaterialInstanceDynamic::Create(WavesRenderTargetMaterial, this);
	WavesRTDynamicMI->AddToRoot();

	/** Create waves render target texture instance */
	WavesRTInstance = UKismetRenderingLibrary::CreateRenderTarget2D(this, WavesRenderTargetTexture->SizeX, WavesRenderTargetTexture->SizeY, RTF_R16f);
	WavesRTInstance->AddToRoot();
	
	/** Assign waves render target texture instance to liquid shader DMI */ 
	LiquidShaderDynamicMI->SetTextureParameterValue("RT Waves Texture", WavesRTInstance);

	if(GenerateCap)
	{
		GenerateCapDynamicInstances();
	}
}

void ULiquidShaderComponent::GenerateCapDynamicInstances()
{
	/** ---------------------------------------------------------------------- Mask ----------------------------------------------------------------------*/
	
	/** Create cap render target texture instance */
	CapRTInstance = UKismetRenderingLibrary::CreateRenderTarget2D(this, CapRenderTargetTexture->SizeX, CapRenderTargetTexture->SizeY);
	CapRTInstance->AddressX = TA_Clamp;
	CapRTInstance->AddressY = TA_Clamp;
	CapRTInstance->AddToRoot();
	
	/** Assign cap render target texture instance to liquid shader DMI */ 
	LiquidShaderDynamicMI->SetTextureParameterValue("RT Cap Texture", CapRTInstance);

	/** ---------------------------------------------------------------------- SDF ----------------------------------------------------------------------*/
		
	/** Create SDF cap mask DMI */
	SDF_CapDistMaskDMI = UMaterialInstanceDynamic::Create(SDF_CapDistanceMaskMaterial, this);
	SDF_CapDistMaskDMI->AddToRoot();
	SDF_CapDistMaskDMI->SetTextureParameterValue("RT Cap Texture", CapRTInstance);

	/** Create SDF cap jump flood DMI */
	SDF_CapJumpFloodDMI = UMaterialInstanceDynamic::Create(SDF_CapJumpFloodMaterial, this);
	SDF_CapJumpFloodDMI->AddToRoot();
		
	/** Create SDF cap render target texture instance */
	RT_SDFCapInstA = UKismetRenderingLibrary::CreateRenderTarget2D(this, CapRenderTargetTexture->SizeX, CapRenderTargetTexture->SizeY);
	RT_SDFCapInstA->AddressX = TA_Clamp;
	RT_SDFCapInstA->AddressY = TA_Clamp;
	RT_SDFCapInstA->RenderTargetFormat = RTF_RG16f;
	RT_SDFCapInstA->LODGroup = TEXTUREGROUP_Pixels2D;
	RT_SDFCapInstA->AddToRoot();

	RT_SDFCapInstB = UKismetRenderingLibrary::CreateRenderTarget2D(this, CapRenderTargetTexture->SizeX, CapRenderTargetTexture->SizeY);
	RT_SDFCapInstB->AddressX = TA_Clamp;
	RT_SDFCapInstB->AddressY = TA_Clamp;
	RT_SDFCapInstB->RenderTargetFormat = RTF_RG16f;
	RT_SDFCapInstB->LODGroup = TEXTUREGROUP_Pixels2D;
	RT_SDFCapInstB->AddToRoot();

	LiquidShaderDynamicMI->SetTextureParameterValue("RT SDF Cap", RT_SDFCapInstB);
}

void ULiquidShaderComponent::GetLiquidComponents()
{
	if(bSMActor)
	{
		AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(GetOwner());
		SMComponent = StaticMeshActor->GetStaticMeshComponent();
	}
	else if (bBlueprint)
	{
		Execute_RequestStaticMeshComponent(GetOwner());
		SMComponent = LS_StaticMeshComponent;
	}
	
	SMLiquidOwner = SMComponent->GetStaticMesh();
	
	/** Find the parent's root from owner */
	if(SMComponent->GetAttachParentActor())
	{
		AActor* TempParent = SMComponent->GetAttachParentActor();
		while (IsValid(TempParent))
		{
			ParentActor = TempParent;
			TempParent = TempParent->GetAttachParentActor();
		}
	}
}

float ULiquidShaderComponent::GetLiquidOffset()
{
	/** Get Liquid Offset from DMI*/
	FMaterialParameterInfo ParameterInfo;
	ParameterInfo.Name = "Liquid - Offset";
	float LOffset;
	
	LiquidShaderDynamicMI->GetScalarParameterValue(ParameterInfo, LOffset);
	return LOffset;
}

void ULiquidShaderComponent::CheckLiquidOffsetBounds()
{
	float LiquidWSPosition = InitialLiquidOffset + SMComponent->GetComponentLocation().Z;
	
	if(LiquidWSPosition >= SMComponent->Bounds.GetBox().Max.Z ||
	LiquidWSPosition <= SMComponent->Bounds.GetBox().Min.Z)
	{
		GenerateCap = false;
		LiquidAdaptation = false;
	}
}

void ULiquidShaderComponent::GetBubbleParameters(float& BubbleAmount)
{
	/** Get bubble parameters from DMI*/
	FMaterialParameterInfo ParameterInfo;
	ParameterInfo.Name = "Bubbles - Main Amount";
	LiquidShaderDynamicMI->GetScalarParameterValue(ParameterInfo, BubbleAmount);
}

void ULiquidShaderComponent::RemoveSDF_FromRoot()
{
	if(IsValid(SDF_CapDistMaskDMI) && IsValid(SDF_CapJumpFloodDMI))
	{
		if((SDF_CapDistMaskDMI->IsRooted() && SDF_CapJumpFloodDMI->IsRooted()))
		{
			SDF_CapDistMaskDMI->RemoveFromRoot();
			SDF_CapJumpFloodDMI->RemoveFromRoot();
			RT_SDFCapInstA->RemoveFromRoot();
			RT_SDFCapInstB->RemoveFromRoot();
		}
	}
}

/** ---------------------------------------------------------------------- Tick ----------------------------------------------------------------------*/

void ULiquidShaderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/** Waves mask ref: https://twitter.com/ShaderBits/status/1268968994247249923 */
	/** Rotation strength*/
		/** Waves */
		FVector UpVector = FRotationMatrix(SMComponent->GetComponentRotation()).GetScaledAxis(EAxis::Z);
		MovementStrength(WavesRotationVectorStrength, PreviousActorUpRotation, UpVector, RotationStrengthReduction,
			WavesRotationStrength, true , WavesRotationVectorStrength, WavesRotationStrength);

		/** Bubbles */
		MovementStrength(BubblesRotationVectorStrength, PreviousActorUpRotation, UpVector, RotationStrengthReduction,
		BubblesRotationStrength, true , BubblesRotationVectorStrength, BubblesRotationStrength);
	
	/** Offset strength*/
		/** Waves */
		MovementStrength(WavesOffsetVectorStrength, PreviousActorLocation,SMComponent->GetComponentLocation(), OffsetStrengthReduction,
			WavesOffsetStrength, false, WavesOffsetVectorStrength, WavesOffsetStrength);

		/** Bubbles */
		MovementStrength(BubblesOffsetVectorStrength, PreviousActorLocation,SMComponent->GetComponentLocation(), OffsetStrengthReduction,
		BubblesOffsetStrength, false, BubblesOffsetVectorStrength, BubblesOffsetStrength);

	
	PreviousActorLocation = SMComponent->GetComponentLocation();
	PreviousActorUpRotation = FRotationMatrix(SMComponent->GetComponentRotation()).GetScaledAxis(EAxis::Z);
		
	/** Decrease Waves */
	DecreaseStrength(DeltaTime);
		
	if(WavesRotationStrength != 0 || WavesRotationVectorStrength != TargetVector || WavesOffsetStrength != 0 || WavesOffsetVectorStrength != TargetVector)
	{
		/** If liquid shader component is child, get his offset */
		if(IsValid(ParentActor))
		{
			RelativeZOffset = SMComponent->GetComponentLocation().Z - ParentActor->GetActorLocation().Z;
		}
			
		/** Draw waves to RT with parameters */
		SetWavesRenderTargetMIParameters();

		if(LiquidAdaptation)
		{
			/** Adapt liquid offset based on volume */ 
			ComputeLiquidVolume(DeltaTime, false);
		}
		
		/** WS Bounds*/
		LiquidShaderDynamicMI->SetVectorParameterValue("Component Origin Bound", SMComponent->Bounds.Origin);
		LiquidShaderDynamicMI->SetVectorParameterValue("Component Max Bound",  SMComponent->Bounds.GetBox().Max);
		LiquidShaderDynamicMI->SetVectorParameterValue("Component Min Bound",  SMComponent->Bounds.GetBox().Min);
		
		/** Apply bubble parameter values*/
		SetBubbleMIParameters(DeltaTime);

		if(GenerateCap)
		{
			/** Cap compute shader */
			EnqueueCS();
		}
	}
	else
	{
		UKismetRenderingLibrary::ClearRenderTarget2D(this, WavesRTInstance);
	}
}

/** ---------------------------------------------------------------------- Side Waves ----------------------------------------------------------------------*/

void ULiquidShaderComponent::MovementStrength(FVector VectorStrength, FVector PreviousUpVector, FVector ActorTransform, float StrengthReduction, float TransformStrength, bool isRotation, FVector& NewVectorStrength, float& NewTransformStrength)
{
	FVector TransformDistance;
	
	/** Distance previous -> current transform */
	if (isRotation)
		TransformDistance = (PreviousUpVector - ActorTransform) * WavesRotationSensitivity;
	else
		TransformDistance = (PreviousUpVector - ActorTransform) * WavesOffsetSensitivity * 10.f;
	
	/** Vector tranform strength*/
	float XTransform = FMath::Clamp(FMath::Max(VectorStrength.X, FMath::Abs(TransformDistance.X)), 0.f, .5f);
	float YTransform = FMath::Clamp(FMath::Max(VectorStrength.Y, FMath::Abs(TransformDistance.Y)), 0.f, .5f);
	float ZTransform = FMath::Clamp(FMath::Max(VectorStrength.Z, FMath::Abs(TransformDistance.Z)), 0.f, .5f);
	
	NewVectorStrength = FVector(XTransform, YTransform, ZTransform);
	
	/** Transform strength*/
	NewTransformStrength = FMath::Max((TransformDistance.Length() / StrengthReduction), TransformStrength);
}

void ULiquidShaderComponent::DecreaseStrength(float DeltaTime)
{
	/** Decreasing waves movement*/
		/** Rotation*/
		WavesRotationStrength = FMath::FInterpTo(WavesRotationStrength, 0.f, DeltaTime, DecreaseWavesStrengthSpeed);
		WavesRotationVectorStrength = FMath::VInterpTo(WavesRotationVectorStrength, TargetVector, DeltaTime, DecreaseVectorStrengthSpeed);

		/** Offset*/
		WavesOffsetStrength = FMath::FInterpTo(WavesOffsetStrength, 0.f, DeltaTime, DecreaseWavesStrengthSpeed);
		WavesOffsetVectorStrength = FMath::VInterpTo(WavesOffsetVectorStrength, TargetVector, DeltaTime, DecreaseVectorStrengthSpeed);
	
	/** Decreasing bubbles movement*/
		float DecreaseBubblesSpeedScale = 2.f;
		/** Rotation*/
		BubblesRotationStrength = FMath::FInterpTo(BubblesRotationStrength, 0.f, DeltaTime, DecreaseWavesStrengthSpeed * DecreaseBubblesSpeedScale);
	
		/** Offset*/
		BubblesOffsetStrength = FMath::FInterpTo(BubblesOffsetStrength, 0.f, DeltaTime, DecreaseVectorStrengthSpeed * DecreaseBubblesSpeedScale);
}

void ULiquidShaderComponent::SetWavesRenderTargetMIParameters()
{
	float BaseWavesIntensity = .25f;
	
	float HighestStrength;
	FVector HighestVectorStrength;

	/** Select highest strength*/
	if(WavesRotationStrength > WavesOffsetStrength * 2.f)
	{
		HighestStrength = FMath::Clamp(WavesRotationStrength, 0.f, BaseWavesIntensity * WavesIntensity);
		HighestVectorStrength = WavesRotationVectorStrength;
	}
	else
	{
		HighestStrength = FMath::Clamp(WavesOffsetStrength, 0.f, BaseWavesIntensity * WavesIntensity);
		HighestVectorStrength = WavesOffsetVectorStrength;
	}
	
	/** Apply waves parameter values*/
	WavesRTDynamicMI->SetScalarParameterValue(TEXT("Strength"), HighestStrength);
	WavesRTDynamicMI->SetScalarParameterValue(TEXT("Viscosity"), Viscosity);
	WavesRTDynamicMI->SetVectorParameterValue(TEXT("VectorStrength"), HighestVectorStrength);
	
	UKismetRenderingLibrary::ClearRenderTarget2D(this, WavesRTInstance);
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, WavesRTInstance, WavesRTDynamicMI);
}

void ULiquidShaderComponent::SetBubbleMIParameters(float DeltaTime)
{
	float HighestAmount;

	/** Select highest strength*/
	if(BubblesRotationStrength > BubblesOffsetStrength * 100.f)
	{
		HighestAmount = FMath::Clamp(BubblesRotationStrength * TargetBubbleAmount * 5.f, 0.f, TargetBubbleAmount);
	}
	else
	{
		HighestAmount = FMath::Clamp(BubblesOffsetStrength * TargetBubbleAmount * 5.f, 0.f, TargetBubbleAmount);
	}
		
	/** Apply bubbles parameters value*/
	LiquidShaderDynamicMI->SetScalarParameterValue(TEXT("Bubbles - Main Amount"), HighestAmount);
}

void ULiquidShaderComponent::ComputeLiquidVolume(float DeltaTime, bool bInitialize)
{
	/** Voxelization ref: https://bronsonzgeb.com/index.php/2021/05/15/simple-mesh-voxelization-in-unity/ */
	FVector MinBound = SMComponent->Bounds.GetBox().Min;
	FVector MaxBound = SMComponent->Bounds.GetBox().Max;
	float ActorZPosition = SMComponent->GetComponentLocation().Z;
	
	FHitResult ROutHit;
	FHitResult LOutHit;
	FCollisionQueryParams CollisionParams;
	CollisionParams.bTraceComplex = true;

	TArray<FVector2d> VoxelLayers;
	float MaxLocalBound = SMLiquidOwner->GetBoundingBox().Max.Z * SMComponent->GetComponentScale().Z;
	float MinLocalBound = SMLiquidOwner->GetBoundingBox().Min.Z * SMComponent->GetComponentScale().Z;
	
	float VoxelSize = (MaxLocalBound - MinLocalBound) / VoxelFactor;

	if(ShowVoxel)
		UE_LOG(LogTemp, Error, TEXT("Voxel Size: %s"), *FString::SanitizeFloat(VoxelSize));

	int XCount = FMath::CeilToInt((MaxBound.X - MinBound.X) / VoxelSize);
	int YCount = FMath::CeilToInt((MaxBound.Y - MinBound.Y) / VoxelSize);
	int ZCount = FMath::CeilToInt((MaxBound.Z - MinBound.Z) / VoxelSize);
	
	float VolumeAmount = 0.f;
	float LastAdaptedLiquidOffset = AdaptedLiquidOffset;
	AdaptedLiquidOffset = 0.f;

	/** Voxelize */
	for (int ZIndex = 0; ZIndex < ZCount; ZIndex++)
	{
		FVector2d CurrentLayer;
		VoxelLayers.Add(CurrentLayer);

		for (int YIndex = 0; YIndex < YCount; YIndex++)
		{
			bool RVectorTrace = true;
			VoxelLayers[ZIndex].Y = VoxelLayers[ZIndex].Y + 1;
			
			for (float XIndex = 0.f; XIndex < XCount; XIndex++)
			{
				VoxelLayers[ZIndex].X = VoxelLayers[ZIndex].X + 1;
				FVector VoxelPosition = FVector(MinBound.X + XIndex * VoxelSize, MinBound.Y + YIndex * VoxelSize, MinBound.Z + ZIndex * VoxelSize);
				
				if(RVectorTrace)
				{
					/** Find voxelization start position */
					bool bHit = SMComponent->LineTraceComponent(ROutHit, VoxelPosition, FVector(MaxBound.X, VoxelPosition.Y, VoxelPosition.Z), CollisionParams);

					/** Get hitted material */
					int32 SectionIndex;
					UMaterialInterface* HittedMaterial = SMComponent->GetMaterialFromCollisionFaceIndex(ROutHit.FaceIndex, SectionIndex);
					
					if(bHit && (HittedMaterial == LiquidShaderDynamicMI || IncludeMaterials.Contains(HittedMaterial))) 
					{
						XIndex += ROutHit.Distance / VoxelSize;
						RVectorTrace = false;
					}
					else if (bHit)
					{
						XIndex += ROutHit.Distance / VoxelSize;
					}
					else
					{
						/** Line trace out of bound */
						break;
					}
				}
				else
				{
					/** Find voxelization end position */
					bool bHit = SMComponent->LineTraceComponent(LOutHit, VoxelPosition, VoxelPosition - FVector(VoxelSize,0,0), CollisionParams);
					if(bHit)
					{
						RVectorTrace = true;
					}
					else
					{
						/** Check the volume set by the user */
						if(bInitialize)
						{
							InitialLiquidVolume = InitialLiquidVolume + VoxelSize;
							if(VoxelPosition.Z - ActorZPosition > InitialLiquidOffset)
							{
								return;
							}
						}
						/** Adapt the offset to fit the starting volume */
						else
						{
							VolumeAmount = VolumeAmount + VoxelSize;

							/** Debug Voxels*/
							if(ShowVoxel)
								DrawDebugBox(GetWorld(), VoxelPosition, FVector(VoxelSize), FColor::Blue , false, 0.0f, 0, .15f);
							
							/** Set Liquid Offset */
							if(InitialLiquidVolume <= VolumeAmount)
							{
								AdaptLiquidOffset(VoxelLayers[ZIndex - 1], VoxelLayers[ZIndex], MinBound, ZIndex, DeltaTime, LastAdaptedLiquidOffset, ActorZPosition, VoxelSize);
								return;
							}
						}
					}
				}
			}
		}
	}
}

void ULiquidShaderComponent::AdaptLiquidOffset(FVector2d LastVoxelLayer, FVector2d CurrentVoxelLayer, FVector MinBound, int ZIndex, float DeltaTime, float LastAdaptedLiquidOffset, float ActorZPosition, float VoxelSize)
{
	/** Last Z layer, XY count */
	int LastXYCount = LastVoxelLayer.X + LastVoxelLayer.Y;
	
	/** Current Z layer, XY count */
	int CurrentXYCount = CurrentVoxelLayer.X + CurrentVoxelLayer.Y;

	FVector2d Input = FVector2d(0,LastXYCount);
	FVector2d Output = FVector2d(ZIndex - 1,ZIndex);

	/** Gradiant Z voxels */
	float ZOffset = FMath::GetMappedRangeValueClamped(Input, Output, CurrentXYCount);
	float NewLiquidOffset = MinBound.Z + ZOffset * VoxelSize - ActorZPosition + RelativeZOffset + VoxelSize;
	
	/** Smoothing liquid adaptation */
	float MinSpeed = 0.f;
	float MaxSpeed = 40.f;
	float SpeedScale = AdaptationSpeedScale;
	
	SpeedScale = SpeedScale * 10;
	float InterpSpeed = FMath::Clamp(WavesRotationStrength * SpeedScale * Viscosity, MinSpeed, MaxSpeed);
								
	float LiquidOffsetScale = FMath::Floor(LastAdaptedLiquidOffset / 10);
	LiquidOffsetScale < 10 ? LiquidOffsetScale = 10 : LiquidOffsetScale;

	LastAdaptedLiquidOffset = FMath::RoundToFloat(LastAdaptedLiquidOffset * LiquidOffsetScale * 10 ) / (10 * LiquidOffsetScale);
	
	/** Result */
	AdaptedLiquidOffset = FMath::FInterpTo(LastAdaptedLiquidOffset, NewLiquidOffset, DeltaTime, InterpSpeed);
	LiquidShaderDynamicMI->SetScalarParameterValue("Liquid - Offset", AdaptedLiquidOffset);
}
/** ---------------------------------------------------------------------- Cap ----------------------------------------------------------------------*/

void ULiquidShaderComponent::InitSMBounds()
{
	FVector MinBound = ((SMLiquidOwner->GetBoundingBox().Min - SMLiquidOwner->GetBounds().Origin) * SMComponent->GetComponentScale());
	FVector MaxBound = ((SMLiquidOwner->GetBoundingBox().Max - SMLiquidOwner->GetBounds().Origin) * SMComponent->GetComponentScale());

	/** Find bound hypothenus */
	float MinBoundSignedLength = MinBound.Length() * FMath::Sign(MinBound.GetMin());
	float MaxBoundSignedLength = MaxBound.Length() * FMath::Sign(MaxBound.GetMax());
	BoundRange = FVector2f(MinBoundSignedLength, MaxBoundSignedLength);

	/** Cap texture size */
	float CapTiling = abs(MinBoundSignedLength) + abs(MaxBoundSignedLength);
	LiquidShaderDynamicMI->SetScalarParameterValue("Cap Texture Tiling", CapTiling);
}

void ULiquidShaderComponent::InitSections()
{
	FStaticMeshSectionArray* Sections = &SMLiquidOwner->GetRenderData()->LODResources[0].Sections;
	
	for (int Section = 0; Section < Sections->Num(); Section++)
	{
		FStaticMeshSection* CurrentSection = &SMLiquidOwner->GetRenderData()->LODResources[0].Sections[Section];

		if(MaterialIndices.Contains(CurrentSection->MaterialIndex))
		{
			/** TODO Change FVector4f to FVector2f which deal w/ 16 bits aligned ?*/
			FVector4f MaterialRange = FVector4f(CurrentSection->MinVertexIndex, CurrentSection->MaxVertexIndex, 0, 0);
			SectionRange.Add(MaterialRange);
		}
	}
}

void ULiquidShaderComponent::EnqueueCS()
{
	/** Buffers */
	FRawStaticIndexBuffer* IndexBuffer = &SMLiquidOwner->GetRenderData()->LODResources[0].IndexBuffer;
	FStaticMeshVertexBuffers* VertexBuffer = &SMLiquidOwner->GetRenderData()->LODResources[0].VertexBuffers;

	/** Liquid position */
	float WorldLiquidOffset = AdaptedLiquidOffset + SMComponent->GetComponentLocation().Z;
	
	/** Object transform */
	FVector BBCenter = SMComponent->Bounds.Origin + RelativeZOffset;
	
	FTransform ActorTransform;
	ActorTransform.SetLocation(BBCenter);
	ActorTransform.SetRotation(SMComponent->GetComponentRotation().Quaternion());
	ActorTransform.SetScale3D(SMComponent->GetComponentScale());
	
	FVector3f BBOriginPosition = FVector3f(SMLiquidOwner->GetBounds().Origin);
	FVector3f WorldPosition = FVector3f(BBCenter);
	FMatrix44f WorldTransform = FMatrix44f(ActorTransform.ToMatrixWithScale());
	
	/** Execute Cap Shader */
	auto IntersectionCS = new (FUTC_LiquidShaderCSManager);
	
	IntersectionCS->PerformIntersection(VertexBuffer, IndexBuffer, WorldLiquidOffset, BoundRange, BBOriginPosition, WorldPosition, SectionRange, WorldTransform, CapRTInstance);
	IntersectionCS->PerformFill(CapRTInstance);
	
	if(CleanUpCap)
	{
		IntersectionCS->PerformCleanUp(CapRTInstance);	
	}
	
	delete (IntersectionCS);

	GenerateSDFCap();
}

void ULiquidShaderComponent::GenerateSDFCap()
{
	/** SDF ref: https://www.froyok.fr/blog/2018-11-realtime-distance-field-textures-in-unreal-engine-4/ */
	bool bUseRT_B = false;
	UKismetRenderingLibrary::ClearRenderTarget2D(this, RT_SDFCapInstA);
	UKismetRenderingLibrary::ClearRenderTarget2D(this, RT_SDFCapInstB);
	
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, RT_SDFCapInstA, SDF_CapDistMaskDMI);

	float Step = 1.f;
	int JumpFloodIteration = FMath::TruncToInt(FMath::LogX(2.f, CapRTInstance->SizeX));
	
	for(int i = 0; i <= JumpFloodIteration; i++)
	{
		Step = Step / 2;
		if(bUseRT_B)
		{
			SDF_CapJumpFloodDMI->SetTextureParameterValue("RT JumpFlood", RT_SDFCapInstB);
			SDF_CapJumpFloodDMI->SetScalarParameterValue("Step Distance", Step);
			UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, RT_SDFCapInstA, SDF_CapJumpFloodDMI);
		}
		else
		{
			SDF_CapJumpFloodDMI->SetTextureParameterValue("RT JumpFlood", RT_SDFCapInstA);
			SDF_CapJumpFloodDMI->SetScalarParameterValue("Step Distance", Step);
			UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, RT_SDFCapInstB, SDF_CapJumpFloodDMI);
		}
	
		bUseRT_B = !bUseRT_B;
	}
}
/** ---------------------------------------------------------------------- Debug ----------------------------------------------------------------------*/

void ULiquidShaderComponent::DebugLineTrace(FVector Start, FVector End, FColor Color)
{
	FHitResult Hit;
	DrawDebugLine(GetWorld(), Start, End, Hit.bBlockingHit ? FColor::Blue : Color, false, 0.0f, 0, 0.05f);
}