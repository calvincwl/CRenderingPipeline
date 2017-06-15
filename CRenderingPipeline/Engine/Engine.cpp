// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Engine.h"



CLEngine::CLEngine()
{
}


CLEngine::~CLEngine()
{
}

bool CLEngine::Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	if (!RenderDevice.Initialize(HInstance, CmdShow, Width, Height)) { return false; }
	
	return true;
}

void CLEngine::Update(float DeltaTime)
{
	static const float MSPerFrame = 1000.0f / 60.0f;
	while (DeltaTime > MSPerFrame)
	{
		// FixedUpdate();
		DeltaTime -= MSPerFrame;
	}
	// Render(MSPerFrame - DeltaTime);
}