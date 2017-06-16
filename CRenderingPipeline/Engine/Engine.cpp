// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "Engine.h"



CEngine::CEngine()
{
}


CEngine::~CEngine()
{
}

bool CEngine::Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	if (!RenderDevice.Initialize(HInstance, CmdShow, Width, Height)) { return false; }
	
	return true;
}

void CEngine::Update(float DeltaTime)
{
	static const float MSPerFrame = 1000.0f / 60.0f;
	while (DeltaTime > MSPerFrame)
	{
		// FixedUpdate();
		DeltaTime -= MSPerFrame;
	}

	RenderDevice.Clear();
	// Render(MSPerFrame - DeltaTime);
	Test.Update(DeltaTime);
	RenderDevice.Draw();
}
