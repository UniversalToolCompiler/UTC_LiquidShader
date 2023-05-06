/** Copyright 2023, Universal Tool Compiler */

#pragma once

#include "CoreMinimal.h"
#include "RenderGraphResources.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"
#include "StaticMeshResources.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/TextureRenderTarget2D.h"

class UTC_LIQUIDSHADERCS_API FUTC_LiquidShaderCSManager
{
public:
	void PerformIntersection(FStaticMeshVertexBuffers*& VertexBuffer, FRawStaticIndexBuffer*& IndexBuffer, float LiquidOffset, FVector2f BoundRange, FVector3f BBOriginPosition, FVector3f WorldPosition, TArray<FVector4f> SectionRange, FMatrix44f WorldTransform, UTextureRenderTarget2D* RenderTarget);
	void PerformFill(UTextureRenderTarget2D* RenderTarget);
	void PerformCleanUp(UTextureRenderTarget2D* RenderTarget);
	
private:
	void Execute_IntersectionRenderThread(FRHICommandListImmediate& RHICmdList, FStaticMeshVertexBuffers* VertexBuffer, FRawStaticIndexBuffer* IndexBuffer, float LiquidOffset, FVector2f BoundRange, FVector3f BBOriginPosition, FVector3f WorldPosition, TArray<FVector4f> SectionRange, FMatrix44f WorldTransform, UTextureRenderTarget2D* RenderTarget);
	void Execute_FillRenderThread(FRHICommandListImmediate& RHICmdList, UTextureRenderTarget2D* RenderTarget);
	void Execute_CleanUpRenderThread(FRHICommandListImmediate& RHICmdList, UTextureRenderTarget2D* RenderTarget);
};