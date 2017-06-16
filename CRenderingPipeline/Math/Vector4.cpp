// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Vector4.h"



FVector4::FVector4(const FVector3& InVector, float InW /* = 1.0f */)
	: X(InVector.X), Y(InVector.Y), Z(InVector.Z), W(InW)
{
}

FVector4::FVector4(float InX /* = 0.0f */, float InY /* = 0.0f */, float InZ /* = 0.0f */, float InW /* = 1.0f */)
	: X(InX), Y(InY), Z(InZ), W(InW)
{
}

FVector4::~FVector4()
{
}
