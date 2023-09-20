/** Copyright 2023, Universal Tool Compiler */

#include "UTC_LiquidShaderCSManager.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "Modules/ModuleManager.h"
#include "ShaderCompilerCore.h"
#include "TextureResource.h"

/** ---------------------------------------------------------------------- Form ----------------------------------------------------------------------*/
class FLiquidShaderCapCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FLiquidShaderCapCS);
	SHADER_USE_PARAMETER_STRUCT(FLiquidShaderCapCS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(float, LiquidOffset)
		SHADER_PARAMETER(int, CapRTSize)
		SHADER_PARAMETER(int, BufferSize)

		SHADER_PARAMETER(FVector2f, BoundRange)
		SHADER_PARAMETER(FVector3f, BBOriginPosition)
		SHADER_PARAMETER(FVector3f, WorldPosition)
		SHADER_PARAMETER(FMatrix44f, WorldTransform)

		SHADER_PARAMETER_ARRAY(FVector4f, SectionRange, [16]) /** <- Max num mat for static mesh */
		SHADER_PARAMETER_SRV(Buffer<FVector>, VertexBuffer)
		SHADER_PARAMETER_SRV(Buffer<uint32>, IndexBuffer)
	
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<FVector4>, OutputTexture)
	END_SHADER_PARAMETER_STRUCT()

	/** Compile only for valid platforms */
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5); }

	/** Compilation environment */
	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), 32);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), 1);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
		OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);
	}
};

IMPLEMENT_GLOBAL_SHADER(FLiquidShaderCapCS, "/Shaders/Private/LiquidShaderCapCS.usf", "MainCS", SF_Compute);

void FUTC_LiquidShaderCSManager::PerformIntersection(FStaticMeshVertexBuffers*& VertexBuffer, FRawStaticIndexBuffer*& IndexBuffer, float LiquidOffset, FVector2f BoundRange, FVector3f BBOriginPosition, FVector3f WorldPosition, TArray<FVector4f> SectionRange, FMatrix44f WorldTransform, UTextureRenderTarget2D* RenderTarget )
{
	FRenderCommandFence Fence;
	
	ENQUEUE_RENDER_COMMAND(PerformLiquidShaderCapCS)
	([this, VertexBuffer, IndexBuffer, LiquidOffset, SectionRange, BoundRange, BBOriginPosition, WorldPosition, WorldTransform, RenderTarget](
			FRHICommandListImmediate& RHICmdList) { this->Execute_IntersectionRenderThread(RHICmdList, VertexBuffer, IndexBuffer, LiquidOffset, BoundRange, BBOriginPosition, WorldPosition, SectionRange, WorldTransform, RenderTarget); });
	Fence.BeginFence();
	Fence.Wait();

}

void FUTC_LiquidShaderCSManager::Execute_IntersectionRenderThread(FRHICommandListImmediate& RHICmdList, FStaticMeshVertexBuffers* VertexBuffer, FRawStaticIndexBuffer* IndexBuffer, float LiquidOffset, FVector2f BoundRange, FVector3f BBOriginPosition, FVector3f WorldPosition, TArray<FVector4f> SectionRange, FMatrix44f WorldTransform, UTextureRenderTarget2D* RenderTarget)
{
	/** Create RDG */
	FMemMark Mark(FMemStack::Get());
	FRDGBuilder GraphBuilder(RHICmdList);
	FLiquidShaderCapCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FLiquidShaderCapCS::FParameters>();

	uint32 BufferSize = FMath::Clamp(IndexBuffer->GetNumIndices() / 3, 0, FVector(GRHIMaxDispatchThreadGroupsPerDimension.GetMax()).X);
	
	/** Inputs */
	PassParameters->LiquidOffset = LiquidOffset;
	PassParameters->BoundRange = BoundRange;
	PassParameters->CapRTSize = RenderTarget->SizeX;

	PassParameters->BBOriginPosition = BBOriginPosition;
	PassParameters->WorldPosition = WorldPosition;
	PassParameters->WorldTransform = WorldTransform;

	int MaxMaterialSlots = 16;
	for (int i = 0; i < SectionRange.Num(); i++)
	{
		PassParameters->SectionRange[i] = SectionRange[i];

		if(i >= MaxMaterialSlots)
			break;
	}
	
	PassParameters->VertexBuffer = VertexBuffer->PositionVertexBuffer.GetSRV();
	
	FRHIViewDesc::FBufferSRV::FInitializer IndexBufferSRV = FRHIViewDesc::CreateBufferSRV();
	IndexBufferSRV.SetType(FRHIViewDesc::EBufferType::Typed);
	IndexBufferSRV.SetFormat(PF_R16_UINT);
	
	PassParameters->IndexBuffer= RHICmdList.CreateShaderResourceView(IndexBuffer->IndexBufferRHI, IndexBufferSRV);
	
	PassParameters->BufferSize = BufferSize;
	
	/** Outputs */
	if(BufferSize > 0 )
	{
		/** Create texture parameter */
		FRDGTextureDesc OutTextureDesc = FRDGTextureDesc::Create2D(FIntPoint(RenderTarget->SizeX, RenderTarget->SizeY), PF_FloatRGBA, FClearValueBinding::Black, TexCreate_RenderTargetable | TexCreate_UAV, 1,1);
		FRDGTextureRef OutTextureRef = GraphBuilder.CreateTexture(OutTextureDesc, TEXT("FormTexture"));
		FRDGTextureUAVDesc OutTextureUAVDesc(OutTextureRef);
		PassParameters->OutputTexture = GraphBuilder.CreateUAV(OutTextureUAVDesc);
		
		TShaderMapRef<FLiquidShaderCapCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
		FIntVector GroupCounts = FIntVector(BufferSize / 3 , 1, 1);
		FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("LiquidFormPass"), ComputeShader, PassParameters, GroupCounts);
		
		TRefCountPtr<IPooledRenderTarget> PooledComputeTarget;
		GraphBuilder.QueueTextureExtraction(OutTextureRef, &PooledComputeTarget);
		 
		/** Execute CS*/
		GraphBuilder.Execute();
	
		/** Copy Pooled Texture to Render Target */
		FRHICopyTextureInfo CopyInfos;
		RHICmdList.CopyTexture(PooledComputeTarget.GetReference()->GetRHI(), RenderTarget->GetRenderTargetResource()->TextureRHI, CopyInfos);
		ClearRenderTarget(RHICmdList, PooledComputeTarget.GetReference()->GetRHI());
	}
}

/** ---------------------------------------------------------------------- Fill ----------------------------------------------------------------------*/

class FLiquidShaderFillCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FLiquidShaderFillCS);
	SHADER_USE_PARAMETER_STRUCT(FLiquidShaderFillCS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(int, RTargetSize)
		SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D, RefTexture)
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<FVector4>, OutputTexture)
	END_SHADER_PARAMETER_STRUCT()

	/** Compile only for valid platforms */
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters){ return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5); }

	/** Compilation environment */
	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), 8);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), 8);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
		OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);
	}
};

IMPLEMENT_GLOBAL_SHADER(FLiquidShaderFillCS, "/Shaders/Private/LiquidShaderFillCS.usf", "MainCS", SF_Compute);

void FUTC_LiquidShaderCSManager::PerformFill( UTextureRenderTarget2D* RenderTarget )
{
	FRenderCommandFence Fence;
	ENQUEUE_RENDER_COMMAND(PerformLiquidShaderFillCS)
	([this,  RenderTarget](
			FRHICommandListImmediate& RHICmdList) { this->Execute_FillRenderThread(RHICmdList, RenderTarget); });
	Fence.BeginFence();
	Fence.Wait();
}

void FUTC_LiquidShaderCSManager::Execute_FillRenderThread(FRHICommandListImmediate& RHICmdList, UTextureRenderTarget2D* RenderTarget)
{
	/** Create RDG */
	FMemMark Mark(FMemStack::Get());
	FRDGBuilder GraphBuilder(RHICmdList);
	FLiquidShaderFillCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FLiquidShaderFillCS::FParameters>();

	PassParameters->RTargetSize = RenderTarget->SizeX;
	
	/** Form texture == Intersection render target */
	TRefCountPtr<IPooledRenderTarget> PooledComputeRef;
	CacheRenderTarget(RenderTarget->GetRenderTargetResource()->TextureRHI, TEXT("CapForm"), PooledComputeRef);
	FRDGTextureRef RenderTargetTextureRef = GraphBuilder.RegisterExternalTexture(PooledComputeRef);
	FRDGTextureSRVDesc RefTextureSRVDesc(RenderTargetTextureRef);
	PassParameters->RefTexture = GraphBuilder.CreateSRV(RefTextureSRVDesc);

	/** Create texture parameter */
	/** Output texture */
	FRDGTextureDesc OutTextureDesc = FRDGTextureDesc::Create2D(FIntPoint(RenderTarget->SizeX, RenderTarget->SizeY), PF_FloatRGBA, FClearValueBinding(), TexCreate_RenderTargetable | TexCreate_UAV, 1,1);
	FRDGTextureRef OutTextureRef = GraphBuilder.CreateTexture(OutTextureDesc, TEXT("FilledTexture"));
	FRDGTextureUAVDesc OutTextureUAVDesc(OutTextureRef);
	PassParameters->OutputTexture = GraphBuilder.CreateUAV(OutTextureUAVDesc);
	
	TShaderMapRef<FLiquidShaderFillCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
	FIntVector GroupCounts = FIntVector(RenderTarget->SizeX / 8 , RenderTarget->SizeX / 8 , 1);
	FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("FillMaskPass"), ComputeShader, PassParameters, GroupCounts);
		
	TRefCountPtr<IPooledRenderTarget> PooledComputeTarget;
	GraphBuilder.QueueTextureExtraction(OutTextureRef, &PooledComputeTarget);

	/** Execute CS*/
	GraphBuilder.Execute();

	/** Copy Pooled Texture to Render Target */
	FRHICopyTextureInfo CopyInfos;
	RHICmdList.CopyTexture(PooledComputeTarget.GetReference()->GetRHI(), RenderTarget->GetRenderTargetResource()->TextureRHI, CopyInfos);
	ClearRenderTarget(RHICmdList, PooledComputeTarget.GetReference()->GetRHI());
	
}

/** ---------------------------------------------------------------------- Clean Up  ----------------------------------------------------------------------*/

class FLiquidShaderCleanUpCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FLiquidShaderCleanUpCS);
	SHADER_USE_PARAMETER_STRUCT(FLiquidShaderCleanUpCS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(int, RTargetSize)
		SHADER_PARAMETER_RDG_TEXTURE_SRV(Texture2D, RefTexture)
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<FVector4>, OutputTexture)
	END_SHADER_PARAMETER_STRUCT()

	/** Compile only for valid platforms */
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5); }

	/** Compilation environment */
	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), 8);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), 8);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
		OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);
	}
};

IMPLEMENT_GLOBAL_SHADER(FLiquidShaderCleanUpCS, "/Shaders/Private/LiquidShaderCleanUpCS.usf", "MainCS", SF_Compute);

void FUTC_LiquidShaderCSManager::PerformCleanUp( UTextureRenderTarget2D* RenderTarget )
{
	FRenderCommandFence Fence;
	ENQUEUE_RENDER_COMMAND(PerformLiquidShaderCleanUpCS)
	([this,  RenderTarget](
			FRHICommandListImmediate& RHICmdList) { this->Execute_CleanUpRenderThread(RHICmdList, RenderTarget); });
	Fence.BeginFence();
	Fence.Wait();
}

void FUTC_LiquidShaderCSManager::Execute_CleanUpRenderThread(FRHICommandListImmediate& RHICmdList, UTextureRenderTarget2D* RenderTarget)
{
	/** Create RDG */
	FMemMark Mark(FMemStack::Get());
	FRDGBuilder GraphBuilder(RHICmdList);
	FLiquidShaderCleanUpCS::FParameters* PassParameters = GraphBuilder.AllocParameters<FLiquidShaderCleanUpCS::FParameters>();

	PassParameters->RTargetSize = RenderTarget->SizeX;
	
	/** Form texture == Intersection render target */
	TRefCountPtr<IPooledRenderTarget> PooledComputeRef;
	CacheRenderTarget(RenderTarget->GetRenderTargetResource()->TextureRHI, TEXT("FilledForm"), PooledComputeRef);
	FRDGTextureRef RenderTargetTextureRef = GraphBuilder.RegisterExternalTexture(PooledComputeRef);
	FRDGTextureSRVDesc RefTextureSRVDesc(RenderTargetTextureRef);
	PassParameters->RefTexture = GraphBuilder.CreateSRV(RefTextureSRVDesc);

	/** Create texture parameter */
	/** Output texture */
	FRDGTextureDesc OutTextureDesc = FRDGTextureDesc::Create2D(FIntPoint(RenderTarget->SizeX, RenderTarget->SizeY), PF_FloatRGBA, FClearValueBinding(), TexCreate_RenderTargetable | TexCreate_UAV, 1,1);
	FRDGTextureRef OutTextureRef = GraphBuilder.CreateTexture(OutTextureDesc, TEXT("CleanedTexture"));
	FRDGTextureUAVDesc OutTextureUAVDesc(OutTextureRef);
	PassParameters->OutputTexture = GraphBuilder.CreateUAV(OutTextureUAVDesc);
	
	TShaderMapRef<FLiquidShaderCleanUpCS> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel));
	FIntVector GroupCounts = FIntVector(RenderTarget->SizeX / 8 , RenderTarget->SizeX / 8 , 1);
	FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("CleanUpPass"), ComputeShader, PassParameters, GroupCounts);
		
	TRefCountPtr<IPooledRenderTarget> PooledComputeTarget;
	GraphBuilder.QueueTextureExtraction(OutTextureRef, &PooledComputeTarget);

	/** Execute CS*/
	GraphBuilder.Execute();

	/** Copy Pooled Texture to Render Target */
	FRHICopyTextureInfo CopyInfos;
	RHICmdList.CopyTexture(PooledComputeTarget.GetReference()->GetRHI(), RenderTarget->GetRenderTargetResource()->TextureRHI, CopyInfos);
	ClearRenderTarget(RHICmdList, PooledComputeTarget.GetReference()->GetRHI());
	
}