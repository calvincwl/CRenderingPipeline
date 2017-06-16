// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <math.h>

class FMath
{
public:
	FMath();
	~FMath();

	static inline float Sqrt(float Value) { return sqrtf(Value); }
	static inline float DegreesToRadians(const float& DegVal)
	{
		return DegVal * (PI / 180.f);
	}
	static inline float Tan(float Value) { return tanf(Value); }
	static const float Float_Epsilon;
	static const float PI;
};

