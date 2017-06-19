// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include "Math/Vector3.h"

class FVector4
{
public:
	float X;
	float Y;
	float Z;
	float W;

	FVector4(const FVector3& InVector, float InW = 1.0f);
	FVector4(float InX = 0.0f, float InY = 0.0f, float InZ = 0.0f, float InW = 1.0f);
	~FVector4();

	FVector4 operator/(float Scale) const;
	FVector4 operator/=(float V);
};

