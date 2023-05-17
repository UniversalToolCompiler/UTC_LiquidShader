// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UTC_LiquidShader/Public/UTC_LSInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUTC_LSInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_UTC_LiquidShader();
	UTC_LIQUIDSHADER_API UClass* Z_Construct_UClass_UUTC_LSInterface();
	UTC_LIQUIDSHADER_API UClass* Z_Construct_UClass_UUTC_LSInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IUTC_LSInterface::execRequestStaticMeshComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestStaticMeshComponent_Implementation();
		P_NATIVE_END;
	}
	void IUTC_LSInterface::RequestStaticMeshComponent()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RequestStaticMeshComponent instead.");
	}
	void UUTC_LSInterface::StaticRegisterNativesUUTC_LSInterface()
	{
		UClass* Class = UUTC_LSInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RequestStaticMeshComponent", &IUTC_LSInterface::execRequestStaticMeshComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Liquid Shader" },
		{ "Comment", "/** Event to get the liquid owner static mesh component */" },
		{ "ModuleRelativePath", "Public/UTC_LSInterface.h" },
		{ "ToolTip", "Event to get the liquid owner static mesh component" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUTC_LSInterface, nullptr, "RequestStaticMeshComponent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUTC_LSInterface);
	UClass* Z_Construct_UClass_UUTC_LSInterface_NoRegister()
	{
		return UUTC_LSInterface::StaticClass();
	}
	struct Z_Construct_UClass_UUTC_LSInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUTC_LSInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_UTC_LiquidShader,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUTC_LSInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUTC_LSInterface_RequestStaticMeshComponent, "RequestStaticMeshComponent" }, // 2839100162
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUTC_LSInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UTC_LSInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUTC_LSInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IUTC_LSInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUTC_LSInterface_Statics::ClassParams = {
		&UUTC_LSInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000040A1u,
		METADATA_PARAMS(Z_Construct_UClass_UUTC_LSInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUTC_LSInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUTC_LSInterface()
	{
		if (!Z_Registration_Info_UClass_UUTC_LSInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUTC_LSInterface.OuterSingleton, Z_Construct_UClass_UUTC_LSInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUTC_LSInterface.OuterSingleton;
	}
	template<> UTC_LIQUIDSHADER_API UClass* StaticClass<UUTC_LSInterface>()
	{
		return UUTC_LSInterface::StaticClass();
	}
	UUTC_LSInterface::UUTC_LSInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUTC_LSInterface);
	UUTC_LSInterface::~UUTC_LSInterface() {}
	static FName NAME_UUTC_LSInterface_RequestStaticMeshComponent = FName(TEXT("RequestStaticMeshComponent"));
	void IUTC_LSInterface::Execute_RequestStaticMeshComponent(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UUTC_LSInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UUTC_LSInterface_RequestStaticMeshComponent);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IUTC_LSInterface*)(O->GetNativeInterfaceAddress(UUTC_LSInterface::StaticClass())))
		{
			I->RequestStaticMeshComponent_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUTC_LSInterface, UUTC_LSInterface::StaticClass, TEXT("UUTC_LSInterface"), &Z_Registration_Info_UClass_UUTC_LSInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUTC_LSInterface), 1817656293U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_3567960512(TEXT("/Script/UTC_LiquidShader"),
		Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
