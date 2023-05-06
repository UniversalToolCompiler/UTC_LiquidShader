/** Copyright 2023, Universal Tool Compiler */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "UTC_LSInterface.h"
#include "LiquidShaderComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTC_LIQUIDSHADER_API ULiquidShaderComponent : public UActorComponent, public IUTC_LSInterface
{
	GENERATED_BODY()

/** ----------------------------------- Functions -----------------------------------*/
public:
	/** Sets default values for this actor's properties*/
	ULiquidShaderComponent();

	/** Called every frame*/
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Event to get the liquid owner static mesh component */
	virtual void RequestStaticMeshComponent_Implementation() override;

protected:
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	bool bIsRunning = false;

private:

	/** Create Dynamic instances for Material Instances and Render Targets */
	void GenerateDynamicInstances();

	/** Create Dynamic instances for Cap Material Instances and Render Targets */
	void GenerateCapDynamicInstances();

	/** Get Liquid shader's static mesh, components and parents */
	void GetLiquidComponents();

	/** Get the liquid amount at begin play */
	float GetLiquidOffset();

	/** Check if the liquid offset is in static mesh bounds */
	void CheckLiquidOffsetBounds();

	/** Get bubble parameter values set in MI*/
	void GetBubbleParameters(float& BubbleAmount);

	/** Get the 2 highest & lowest values of SM BoundingBox*/
	void InitSMBounds();

	/** Find sections which own liquid shader */
	void InitSections();
	
	/** Compute wave strength based on Actor Movement*/
	void MovementStrength(FVector VectorStrength, FVector PreviousUpVector, FVector ActorTransform, float StrengthReduction, float TransformStrength, bool isRotation, FVector& NewVectorStrength, float& NewTransformStrength);

	/** Decrease strength to stable state*/
	void DecreaseStrength(float DeltaTime);

	/** Apply new values to Waves render target material instance*/
	void SetWavesRenderTargetMIParameters();
	
	/** Voxelize the static mesh and set the liquid volume */
	void ComputeLiquidVolume(float DeltaTime, bool bInitialize);

	/** Apply new values to bubbles parameters*/
	void SetBubbleMIParameters(float DeltaTime);

	/** Modify the liquid offset relatively to liquid volume */
	void AdaptLiquidOffset(FVector2d LastVoxelLayer, FVector2d CurrentVoxelLayer, FVector MinBound, int ZIndex, float DeltaTime, float LastAdaptedLiquidOffset, float ActorZPosition, float VoxelSize);

	/** Run cap shader */
	void EnqueueCS();

	/** Create the signed distance field cap mask texture */ 
	void GenerateSDFCap();

	/** Remove SDF instances from root */
	void RemoveSDF_FromRoot();
	
	//debug
	void DebugLineTrace(FVector Start, FVector End, FColor Color);
	
/** ----------------------------------- Editor Variables -----------------------------------*/
public:
	
	/** The liquid material instance*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Global")
	UMaterialInterface* LiquidMaterialInstance;

	/** All materials that are not liquid shader but are used to close the cap and adapt the liquid offset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Global")
	TArray<UMaterialInterface*> IncludeMaterials;

	/** Only for liquid shader in a BP, set the static mesh component which display the liquid shader */
	UPROPERTY(BlueprintReadWrite, Category = "LiquidSettings|Global|Blueprint")
	UStaticMeshComponent* LS_StaticMeshComponent;

	/** The waves' intensity*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves")
	float WavesIntensity;

	/** How the Rotation strength affects waves*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves")
	float WavesRotationSensitivity;

	/** How the Offset strength affects waves*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves")
	float WavesOffsetSensitivity;

	/** The liquid viscosity*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves")
	float Viscosity;
	
	/** Material which drives waves Render Target*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves|Advanced")
	UMaterialInterface* WavesRenderTargetMaterial;

	/** Render Target which drives waves*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Waves|Advanced")
	UTextureRenderTarget2D* WavesRenderTargetTexture;

	/** Debug voxelized volume  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Liquid Adaptation", meta = (EditCondition = "LiquidAdaptation"))
	bool ShowVoxel;

	/** The voxel's factor, set the voxel's size relative to object bound size*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Liquid Adaptation", meta = (EditCondition = "LiquidAdaptation"))
	float VoxelFactor;

	/** Higher value hides the liquid's adaptation and removes compression effect for fast rotation but could create stuttering for slow rotation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Liquid Adaptation", meta = (EditCondition = "LiquidAdaptation"))
	float AdaptationSpeedScale;
	
	/** Mask material to feed the jump flood material*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Cap|Advanced", meta = (EditCondition = "GenerateCap"))
	UMaterialInterface* SDF_CapDistanceMaskMaterial;

	/** Jump flood material to create SDF texture */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Cap|Advanced", meta = (EditCondition = "GenerateCap"))
	UMaterialInterface* SDF_CapJumpFloodMaterial;

	/** Render Target to draw the cap form*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LiquidSettings|Cap|Advanced", meta = (EditCondition = "GenerateCap"))
	UTextureRenderTarget2D* CapRenderTargetTexture;

	/** Enable the compute shader to create the liquid cap (Liquid surface)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LiquidSettings|Optimization")
	bool GenerateCap;

	/** Add a clean up pass to the cap render target to remove filling imperfections */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LiquidSettings|Optimization", meta = (EditCondition = "GenerateCap"))
	bool CleanUpCap;

	/** For non uniform objects and uncentered pivot point, compute the object volume to set the adapted liquid offset */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "LiquidSettings|Optimization")
	bool LiquidAdaptation;
	
/** ----------------------------------- Liquid Owner -----------------------------------*/
private:
	/** The static mesh liquid shader owner*/
	UStaticMesh* SMLiquidOwner;

	/** The static mesh component liquid shader owner*/
	UStaticMeshComponent* SMComponent;

	/** Get the liquid shader component parent */ 
	AActor* ParentActor;

	/** True if liquid shader is owned by a static mesh actor*/
	bool bSMActor = false;

	/** True if liquid shader is owned by a Blueprint*/
	bool bBlueprint = false;

/** ----------------------------------- Side Waves / Liquid Adaptation  -----------------------------------*/
		/** Actor Rotation*/
			/** Current actor rotation strength*/
			FVector WavesRotationVectorStrength;

			/** Previous actor up rotation vector*/
			FVector PreviousActorUpRotation;

			/** Waves rotation strength*/
			float WavesRotationStrength;

			/** Reduce rotation strength*/
			float RotationStrengthReduction = 1.5f;
	
		/** Actor Offset*/
			/** Current actor offset strength*/
			FVector WavesOffsetVectorStrength;

			/** Previous actor location vector*/
			FVector PreviousActorLocation;

			/** Waves offset strength*/
			float WavesOffsetStrength;

			/** Reduce offset strength*/
			float OffsetStrengthReduction = 5000.f;

	/** Waves movements decreasing speed*/
	float DecreaseWavesStrengthSpeed = 1.f;
	float DecreaseVectorStrengthSpeed = .75f;
	
	/** Waves Render Target Material Instance */
	UMaterialInstanceDynamic* WavesRTDynamicMI;
	
	/** Liquid Shader material instance */
	UMaterialInstanceDynamic* LiquidShaderDynamicMI;

	/** Waves Render Target texture instance */
	UTextureRenderTarget2D* WavesRTInstance;

	/** Target waves reduction */
	FVector TargetVector = FVector(0.2f,0.2f,0.2f);

	/** Initial Liquid offset */
	float InitialLiquidOffset;

	/** Initial Liquid Volume */
	float InitialLiquidVolume;

	/** New Liquid offset */
	float AdaptedLiquidOffset;

	/** Z Distance parent -> liquid shader component if is child */
	float RelativeZOffset = 0;

	bool bLiquidAdaptationIsInit = false;
	
/** ----------------------------------- Bubbles -----------------------------------*/
	/** Target bubble amount */
	float TargetBubbleAmount;

	/** Bubbles rotation strength*/
	float BubblesRotationStrength;

	/** Current actor rotation strength*/
	FVector BubblesRotationVectorStrength;

	/** Bubbles offset strength*/
	float BubblesOffsetStrength;

	/** Current actor offset strength*/
	FVector BubblesOffsetVectorStrength;
	
/** ----------------------------------- Cap -----------------------------------*/
	
	/** Cap Render Target texture instance */
	UTextureRenderTarget2D* CapRTInstance;

	/** Render targets to draw the cap jump flood */
	UTextureRenderTarget2D* RT_SDFCapInstA;
	UTextureRenderTarget2D* RT_SDFCapInstB;

	/** Materials to draw on SDF cap RT */
	UMaterialInstanceDynamic* SDF_CapDistMaskDMI;
	UMaterialInstanceDynamic* SDF_CapJumpFloodDMI;

	/** Bounding box's max position value*/
	FVector2f BoundRange;

	/** Material index where liquid shader is applied*/
	TArray<int> MaterialIndices;

	/** Range of vertex index that own liquid shader */
	TArray<FVector4f> SectionRange;
	
};


