/** Copyright 2023, Universal Tool Compiler */

#include "UTC_LiquidShader.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FUTC_LiquidShaderModule"

void FUTC_LiquidShaderModule::StartupModule()
{

}

void FUTC_LiquidShaderModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUTC_LiquidShaderModule, UTC_LiquidShader)