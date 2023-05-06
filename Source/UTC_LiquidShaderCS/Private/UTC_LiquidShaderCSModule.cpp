/** Copyright 2023, Universal Tool Compiler */

#include "UTC_LiquidShaderCSModule.h"
#include "Interfaces/IPluginManager.h"

IMPLEMENT_MODULE(FUTC_LiquidShaderCSModule, UTC_LiquidShaderCS)
#define LOCTEXT_NAMESPACE "FUTC_LiquidShaderCSModule"

void FUTC_LiquidShaderCSModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Maps virtual shader source directory to the plugin's actual shaders directory.
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("UTC_LiquidShader"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Shaders"), PluginShaderDir);
}

void FUTC_LiquidShaderCSModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

