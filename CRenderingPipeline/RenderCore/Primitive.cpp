// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Primitive.h"
#include <string.h>



CPrimitive::CPrimitive()
{
}

CPrimitive::CPrimitive(const CPrimitive& Primitive)
{
	memcpy(V, Primitive.V, sizeof(V));
}

CPrimitive::~CPrimitive()
{
}
