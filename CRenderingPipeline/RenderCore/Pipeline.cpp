// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Pipeline.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"


FPipeline::FPipeline()
{
	VertexBuffer.reserve(MaxBufferSize);
}


FPipeline::~FPipeline()
{
}

void FPipeline::SetViewport(int X, int Y, int Width, int Height)
{
	float MaxZ = 1;
	float MinZ = 0;

	ViewportMatrix.Set
	(
		Width / 2.0f,		0.0f,				0.0f,			0.0f,
		0.0f,				-Height / 2.0f,		0.0f,			0.0f,
		0.0f,				0.0f,				MaxZ - MinZ,	0.0f,
		X + Width / 2.0f,	Y + Height / 2.0f,	MinZ,			1.0f
	);
}

void FPipeline::Update(float DeltaTime)
{
	CCamera& Camera = CEngine::Instance().GetCamera();
	FMatrix VP = Camera.GetViewMatrix() * Camera.GetProjectileMatrix();

	for (CPrimitive Primitive : VertexBuffer)
	{
		FVector4 Vertex = VP.TransformPosition(Primitive.V[0]);
		Vertex = ViewportMatrix.TransformFVector4(Vertex / Vertex.W);
		FVector2 V0(Vertex.X, Vertex.Y);
		Vertex = VP.TransformPosition(Primitive.V[1]);
		Vertex = ViewportMatrix.TransformFVector4(Vertex / Vertex.W);
		FVector2 V1(Vertex.X, Vertex.Y);
		Vertex = VP.TransformPosition(Primitive.V[2]);
		Vertex = ViewportMatrix.TransformFVector4(Vertex / Vertex.W);
		FVector2 V2(Vertex.X, Vertex.Y);

		DrawLine(V0, V1);
		DrawLine(V1, V2);
		DrawLine(V2, V0);
	}

	VertexBuffer.clear();
}

void FPipeline::DrawPrimitive(const CPrimitive& Primitive)
{
	VertexBuffer.push_back(Primitive);
}

void FPipeline::DrawLine(FVector2 Start, FVector2 End)
{
	//int X0 = (int)Start.X;
	//int Y0 = (int)Start.Y;
	//int X1 = (int)End.X;
	//int Y1 = (int)End.Y;

	//if (Y1 < Y0 || (X1 - X0 <= Y1 - Y0))
	//{

	//}
	//int Y = Y0;
	//int D = 2 * (Y0 - Y1) * (X0 + 1) + (X1 - X0) * (2 * Y0 + 1) + 2 * X0 * Y1 - 2 * X1 * Y0;
	//for (int X = X0; X <= X1; ++X)
	//{
	//	CEngine::Instance().GetRenderDevice().SetPixel(X, Y, 0xFFFFFF);
	//	D += 2 * (Y0 - Y1);
	//	if (D < 0)
	//	{
	//		++Y;
	//		D += 2 * (X1 - X0);
	//	}
	//}

	int X0 = (int)Start.X;
	int Y0 = (int)Start.Y;
	int X1 = (int)End.X;
	int Y1 = (int)End.Y;

	// 使用DDA算法进行画直线
	float Steps = float(abs(X1 - X0) > abs(Y1 - Y0) ? abs(X1 - X0) : abs(Y1 - Y0));

	float IncX = (float)(X1 - X0) / Steps;
	float IncY = (float)(Y1 - Y0) / Steps;

	float X = (float)X0;
	float Y = (float)Y0;

	for (int i = 1; i <= Steps; ++i)
	{
		// 绘制像素点
		CEngine::Instance().GetRenderDevice().SetPixel((int)X, (int)Y, RGB(255, 255, 255));

		X += IncX;
		Y += IncY;
	}
}
