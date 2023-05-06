/** Copyright 2023, Universal Tool Compiler */

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FUTC_LiquidShaderModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
