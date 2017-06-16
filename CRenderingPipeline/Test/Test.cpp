// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Test.h"
#include "Engine/Engine.h"



CTest::CTest()
{
}


CTest::~CTest()
{
}

void CTest::Update(float DeltaTime)
{
	for (int i = 0; i < 200; ++i)
	{
		CEngine::Instance().GetRenderDevice().SetPixel(i, i, 0xFF0000);
	}
}
