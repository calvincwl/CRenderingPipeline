// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <vector>
#include "Math/Matrix.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Primitive.h"

class FPipeline
{
	friend class CEngine;

public:
	void SetViewport(int X, int Y, int Width, int Height);
	void Update(float DeltaTime);
	void DrawPrimitive(const CPrimitive& Primitive);
	void DrawLine(FVector2 Start, FVector2 End);

private:
	FPipeline();
	~FPipeline();

	static const int MaxBufferSize = 1024;
	FMatrix ViewportMatrix;
	std::vector<CPrimitive> VertexBuffer;
};

