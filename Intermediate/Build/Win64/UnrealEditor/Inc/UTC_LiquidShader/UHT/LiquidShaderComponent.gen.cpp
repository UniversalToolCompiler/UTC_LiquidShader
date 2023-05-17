// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UTC_LiquidShader/Public/LiquidShaderComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLiquidShaderComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UTC_LiquidShader();
	UTC_LIQUIDSHADER_API UClass* Z_Construct_UClass_ULiquidShaderComponent();
	UTC_LIQUIDSHADER_API UClass* Z_Construct_UClass_ULiquidShaderComponent_NoRegister();
	UTC_LIQUIDSHADER_API UClass* Z_Construct_UClass_UUTC_LSInterface_NoRegister();
// End Cross Module References
	void ULiquidShaderComponent::StaticRegisterNativesULiquidShaderComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULiquidShaderComponent);
	UClass* Z_Construct_UClass_ULiquidShaderComponent_NoRegister()
	{
		return ULiquidShaderComponent::StaticClass();
	}
	struct Z_Construct_UClass_ULiquidShaderComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LiquidMaterialInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LiquidMaterialInstance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IncludeMaterials_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IncludeMaterials_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_IncludeMaterials;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LS_StaticMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LS_StaticMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WavesIntensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WavesIntensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WavesRotationSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WavesRotationSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WavesOffsetSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WavesOffsetSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Viscosity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Viscosity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WavesRenderTargetMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WavesRenderTargetMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WavesRenderTargetTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WavesRenderTargetTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShowVoxel_MetaData[];
#endif
		static void NewProp_ShowVoxel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShowVoxel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VoxelFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VoxelFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdaptationSpeedScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AdaptationSpeedScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SDF_CapDistanceMaskMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SDF_CapDistanceMaskMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SDF_CapJumpFloodMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SDF_CapJumpFloodMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CapRenderTargetTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CapRenderTargetTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GenerateCap_MetaData[];
#endif
		static void NewProp_GenerateCap_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_GenerateCap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CleanUpCap_MetaData[];
#endif
		static void NewProp_CleanUpCap_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CleanUpCap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LiquidAdaptation_MetaData[];
#endif
		static void NewProp_LiquidAdaptation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_LiquidAdaptation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULiquidShaderComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UTC_LiquidShader,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "LiquidShaderComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidMaterialInstance_MetaData[] = {
		{ "Category", "LiquidSettings|Global" },
		{ "Comment", "/** The liquid material instance*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "The liquid material instance" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidMaterialInstance = { "LiquidMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, LiquidMaterialInstance), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidMaterialInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidMaterialInstance_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials_Inner = { "IncludeMaterials", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials_MetaData[] = {
		{ "Category", "LiquidSettings|Global" },
		{ "Comment", "/** All materials that are not liquid shader but are used to close the cap and adapt the liquid offset */" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "All materials that are not liquid shader but are used to close the cap and adapt the liquid offset" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials = { "IncludeMaterials", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, IncludeMaterials), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LS_StaticMeshComponent_MetaData[] = {
		{ "Category", "LiquidSettings|Global|Blueprint" },
		{ "Comment", "/** Only for liquid shader in a BP, set the static mesh component which display the liquid shader */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Only for liquid shader in a BP, set the static mesh component which display the liquid shader" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LS_StaticMeshComponent = { "LS_StaticMeshComponent", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, LS_StaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LS_StaticMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LS_StaticMeshComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesIntensity_MetaData[] = {
		{ "Category", "LiquidSettings|Waves" },
		{ "Comment", "/** The waves' intensity*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "The waves' intensity" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesIntensity = { "WavesIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, WavesIntensity), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesIntensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesIntensity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRotationSensitivity_MetaData[] = {
		{ "Category", "LiquidSettings|Waves" },
		{ "Comment", "/** How the Rotation strength affects waves*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "How the Rotation strength affects waves" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRotationSensitivity = { "WavesRotationSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, WavesRotationSensitivity), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRotationSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRotationSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesOffsetSensitivity_MetaData[] = {
		{ "Category", "LiquidSettings|Waves" },
		{ "Comment", "/** How the Offset strength affects waves*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "How the Offset strength affects waves" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesOffsetSensitivity = { "WavesOffsetSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, WavesOffsetSensitivity), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesOffsetSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesOffsetSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_Viscosity_MetaData[] = {
		{ "Category", "LiquidSettings|Waves" },
		{ "Comment", "/** The liquid viscosity*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "The liquid viscosity" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_Viscosity = { "Viscosity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, Viscosity), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_Viscosity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_Viscosity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetMaterial_MetaData[] = {
		{ "Category", "LiquidSettings|Waves|Advanced" },
		{ "Comment", "/** Material which drives waves Render Target*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Material which drives waves Render Target" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetMaterial = { "WavesRenderTargetMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, WavesRenderTargetMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetTexture_MetaData[] = {
		{ "Category", "LiquidSettings|Waves|Advanced" },
		{ "Comment", "/** Render Target which drives waves*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Render Target which drives waves" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetTexture = { "WavesRenderTargetTexture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, WavesRenderTargetTexture), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel_MetaData[] = {
		{ "Category", "LiquidSettings|Liquid Adaptation" },
		{ "Comment", "/** Debug voxelized volume  */" },
		{ "EditCondition", "LiquidAdaptation" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Debug voxelized volume" },
	};
#endif
	void Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel_SetBit(void* Obj)
	{
		((ULiquidShaderComponent*)Obj)->ShowVoxel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel = { "ShowVoxel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ULiquidShaderComponent), &Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_VoxelFactor_MetaData[] = {
		{ "Category", "LiquidSettings|Liquid Adaptation" },
		{ "Comment", "/** The voxel's factor, set the voxel's size relative to object bound size*/" },
		{ "EditCondition", "LiquidAdaptation" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "The voxel's factor, set the voxel's size relative to object bound size" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_VoxelFactor = { "VoxelFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, VoxelFactor), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_VoxelFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_VoxelFactor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_AdaptationSpeedScale_MetaData[] = {
		{ "Category", "LiquidSettings|Liquid Adaptation" },
		{ "Comment", "/** Higher value hides the liquid's adaptation and removes compression effect for fast rotation but could create stuttering for slow rotation */" },
		{ "EditCondition", "LiquidAdaptation" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Higher value hides the liquid's adaptation and removes compression effect for fast rotation but could create stuttering for slow rotation" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_AdaptationSpeedScale = { "AdaptationSpeedScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, AdaptationSpeedScale), METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_AdaptationSpeedScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_AdaptationSpeedScale_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapDistanceMaskMaterial_MetaData[] = {
		{ "Category", "LiquidSettings|Cap|Advanced" },
		{ "Comment", "/** Mask material to feed the jump flood material*/" },
		{ "EditCondition", "GenerateCap" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Mask material to feed the jump flood material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapDistanceMaskMaterial = { "SDF_CapDistanceMaskMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, SDF_CapDistanceMaskMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapDistanceMaskMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapDistanceMaskMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapJumpFloodMaterial_MetaData[] = {
		{ "Category", "LiquidSettings|Cap|Advanced" },
		{ "Comment", "/** Jump flood material to create SDF texture */" },
		{ "EditCondition", "GenerateCap" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Jump flood material to create SDF texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapJumpFloodMaterial = { "SDF_CapJumpFloodMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, SDF_CapJumpFloodMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapJumpFloodMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapJumpFloodMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CapRenderTargetTexture_MetaData[] = {
		{ "Category", "LiquidSettings|Cap|Advanced" },
		{ "Comment", "/** Render Target to draw the cap form*/" },
		{ "EditCondition", "GenerateCap" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Render Target to draw the cap form" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CapRenderTargetTexture = { "CapRenderTargetTexture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ULiquidShaderComponent, CapRenderTargetTexture), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CapRenderTargetTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CapRenderTargetTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap_MetaData[] = {
		{ "Category", "LiquidSettings|Optimization" },
		{ "Comment", "/** Enable the compute shader to create the liquid cap (Liquid surface)*/" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Enable the compute shader to create the liquid cap (Liquid surface)" },
	};
#endif
	void Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap_SetBit(void* Obj)
	{
		((ULiquidShaderComponent*)Obj)->GenerateCap = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap = { "GenerateCap", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ULiquidShaderComponent), &Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap_MetaData[] = {
		{ "Category", "LiquidSettings|Optimization" },
		{ "Comment", "/** Add a clean up pass to the cap render target to remove filling imperfections */" },
		{ "EditCondition", "GenerateCap" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "Add a clean up pass to the cap render target to remove filling imperfections" },
	};
#endif
	void Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap_SetBit(void* Obj)
	{
		((ULiquidShaderComponent*)Obj)->CleanUpCap = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap = { "CleanUpCap", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ULiquidShaderComponent), &Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation_MetaData[] = {
		{ "Category", "LiquidSettings|Optimization" },
		{ "Comment", "/** For non uniform objects and uncentered pivot point, compute the object volume to set the adapted liquid offset */" },
		{ "ModuleRelativePath", "Public/LiquidShaderComponent.h" },
		{ "ToolTip", "For non uniform objects and uncentered pivot point, compute the object volume to set the adapted liquid offset" },
	};
#endif
	void Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation_SetBit(void* Obj)
	{
		((ULiquidShaderComponent*)Obj)->LiquidAdaptation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation = { "LiquidAdaptation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ULiquidShaderComponent), &Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation_SetBit, METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULiquidShaderComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidMaterialInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_IncludeMaterials,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LS_StaticMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesIntensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRotationSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesOffsetSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_Viscosity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_WavesRenderTargetTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_ShowVoxel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_VoxelFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_AdaptationSpeedScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapDistanceMaskMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_SDF_CapJumpFloodMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CapRenderTargetTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_GenerateCap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_CleanUpCap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULiquidShaderComponent_Statics::NewProp_LiquidAdaptation,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ULiquidShaderComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UUTC_LSInterface_NoRegister, (int32)VTABLE_OFFSET(ULiquidShaderComponent, IUTC_LSInterface), false },  // 1817656293
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULiquidShaderComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULiquidShaderComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULiquidShaderComponent_Statics::ClassParams = {
		&ULiquidShaderComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULiquidShaderComponent_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ULiquidShaderComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULiquidShaderComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULiquidShaderComponent()
	{
		if (!Z_Registration_Info_UClass_ULiquidShaderComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULiquidShaderComponent.OuterSingleton, Z_Construct_UClass_ULiquidShaderComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULiquidShaderComponent.OuterSingleton;
	}
	template<> UTC_LIQUIDSHADER_API UClass* StaticClass<ULiquidShaderComponent>()
	{
		return ULiquidShaderComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULiquidShaderComponent);
	ULiquidShaderComponent::~ULiquidShaderComponent() {}
	struct Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_LiquidShaderComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_LiquidShaderComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULiquidShaderComponent, ULiquidShaderComponent::StaticClass, TEXT("ULiquidShaderComponent"), &Z_Registration_Info_UClass_ULiquidShaderComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULiquidShaderComponent), 1018006540U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_LiquidShaderComponent_h_1481840184(TEXT("/Script/UTC_LiquidShader"),
		Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_LiquidShaderComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_LiquidShaderComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
