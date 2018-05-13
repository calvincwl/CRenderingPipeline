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

	Camera.SetData(0.1f, 1000.0f, 60.0f, 1.333333f);
	Pipeline.SetViewport(0, 0, Width, Height);
	
	return true;
}

void CEngine::Update(float DeltaTime)
{
	static const float MSPerFrame = 1000.0f / 60.0f;
	while (DeltaTime > MSPerFrame)
	{
		// FixedUpdate(MSPerFrame);
		DeltaTime -= MSPerFrame;
	}

	RenderDevice.Clear();

	Test.Update(DeltaTime);
	Camera.Update(DeltaTime);
	Pipeline.Update(DeltaTime);

	RenderDevice.Draw();
}

void CEngine::DrawPrimitive(const CPrimitive& Primitive)
{
	Instance().Pipeline.DrawPrimitive(Primitive);
}
