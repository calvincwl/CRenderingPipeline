// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include "Math/Vector3.h"

class CPrimitive
{
public:
	CPrimitive();
	CPrimitive(const CPrimitive& Primitive);
	~CPrimitive();

	FVector3 V[3];
};

