// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UTC_LSInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UTC_LIQUIDSHADER_UTC_LSInterface_generated_h
#error "UTC_LSInterface.generated.h already included, missing '#pragma once' in UTC_LSInterface.h"
#endif
#define UTC_LIQUIDSHADER_UTC_LSInterface_generated_h

#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_SPARSE_DATA
#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_RPC_WRAPPERS \
	virtual void RequestStaticMeshComponent_Implementation() {}; \
 \
	DECLARE_FUNCTION(execRequestStaticMeshComponent);


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void RequestStaticMeshComponent_Implementation() {}; \
 \
	DECLARE_FUNCTION(execRequestStaticMeshComponent);


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_ACCESSORS
#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_CALLBACK_WRAPPERS
#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUTC_LSInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUTC_LSInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUTC_LSInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUTC_LSInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUTC_LSInterface(UUTC_LSInterface&&); \
	NO_API UUTC_LSInterface(const UUTC_LSInterface&); \
public: \
	NO_API virtual ~UUTC_LSInterface();


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUTC_LSInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUTC_LSInterface(UUTC_LSInterface&&); \
	NO_API UUTC_LSInterface(const UUTC_LSInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUTC_LSInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUTC_LSInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUTC_LSInterface) \
	NO_API virtual ~UUTC_LSInterface();


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUUTC_LSInterface(); \
	friend struct Z_Construct_UClass_UUTC_LSInterface_Statics; \
public: \
	DECLARE_CLASS(UUTC_LSInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/UTC_LiquidShader"), NO_API) \
	DECLARE_SERIALIZER(UUTC_LSInterface)


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_GENERATED_UINTERFACE_BODY() \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_GENERATED_UINTERFACE_BODY() \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IUTC_LSInterface() {} \
public: \
	typedef UUTC_LSInterface UClassType; \
	typedef IUTC_LSInterface ThisClass; \
	static void Execute_RequestStaticMeshComponent(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_INCLASS_IINTERFACE \
protected: \
	virtual ~IUTC_LSInterface() {} \
public: \
	typedef UUTC_LSInterface UClassType; \
	typedef IUTC_LSInterface ThisClass; \
	static void Execute_RequestStaticMeshComponent(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_9_PROLOG
#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_SPARSE_DATA \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_RPC_WRAPPERS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_ACCESSORS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_CALLBACK_WRAPPERS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_SPARSE_DATA \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_ACCESSORS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_CALLBACK_WRAPPERS \
	FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UTC_LIQUIDSHADER_API UClass* StaticClass<class UUTC_LSInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Downloads_UTC_LiquidShader_Update_HostProject_Plugins_UTC_LiquidShader_Source_UTC_LiquidShader_Public_UTC_LSInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
