// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Test.h"
#include "Engine/Engine.h"
#include "RenderCore/Primitive.h"



CTest::CTest()
{
}


CTest::~CTest()
{
}

void CTest::Update(float DeltaTime)
{
	//////////////////////////////////////////////////////////////////////////
	// cube model
	FVector3 CubeVertexArray[] = {
		FVector3(-1.0f, -1.0f, -1.0f),
		FVector3(-1.0f, 1.0f, -1.0f),
		FVector3(1.0f, 1.0f, -1.0f),
		FVector3(1.0f, -1.0f, -1.0f),
		FVector3(-1.0f, -1.0f, 1.0f),
		FVector3(-1.0f, 1.0f, 1.0f),
		FVector3(1.0f, 1.0f, 1.0f),
		FVector3(1.0f, -1.0f, 1.0f)
	};

	int Face[36];

	// Front face.
	Face[0] = 0; Face[1] = 1; Face[2] = 2;
	Face[3] = 0; Face[4] = 2; Face[5] = 3;

	// Back face.
	Face[6] = 4; Face[7] = 6; Face[8] = 5;
	Face[9] = 4; Face[10] = 7; Face[11] = 6;

	// Left face.
	Face[12] = 4; Face[13] = 5; Face[14] = 1;
	Face[15] = 4; Face[16] = 1; Face[17] = 0;

	// Right face.
	Face[18] = 3; Face[19] = 2; Face[20] = 6;
	Face[21] = 3; Face[22] = 6; Face[23] = 7;

	// Top face.
	Face[24] = 1; Face[25] = 5; Face[26] = 6;
	Face[27] = 1; Face[28] = 6; Face[29] = 2;

	// Bottom face.
	Face[30] = 4; Face[31] = 0; Face[32] = 3;
	Face[33] = 4; Face[34] = 3; Face[35] = 7;

	for (int i = 0; i < 36; i += 3)
	{
		CPrimitive Primitive;
		Primitive.V[0] = CubeVertexArray[Face[i]];
		Primitive.V[1] = CubeVertexArray[Face[i + 1]];
		Primitive.V[2] = CubeVertexArray[Face[i + 2]];

		CEngine::DrawPrimitive(Primitive);
	}
}
