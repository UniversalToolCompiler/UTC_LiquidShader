/** Copyright 2023, Universal Tool Compiler */

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UTC_LSInterface.generated.h"

UINTERFACE()
class UUTC_LSInterface : public UInterface
{
	GENERATED_BODY()
};

class UTC_LIQUIDSHADER_API IUTC_LSInterface
{
	GENERATED_BODY()
	
public:
	/** Event to get the liquid owner static mesh component */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Liquid Shader")
	void RequestStaticMeshComponent();
};
