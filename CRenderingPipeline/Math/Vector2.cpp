// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Vector2.h"



FVector2::FVector2(float InX /* = 0.0f */, float InY /* = 0.0f */)
	: X(InX), Y(InY)
{
}


FVector2::~FVector2()
{
}

FVector2& FVector2::operator=(const FVector2& V)
{
	X = V.X;
	Y = V.Y;

	return *this;
}
