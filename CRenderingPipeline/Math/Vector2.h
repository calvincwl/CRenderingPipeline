// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

class FVector2
{
public:
	float X;
	float Y;

	FVector2(float InX = 0.0f, float InY = 0.0f);
	~FVector2();

	FVector2& operator=(const FVector2& V);
};

