// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>
#include "Utils/Singleton.h"
#include "RenderCore/RenderDevice.h"
#include "RenderCore/Pipeline.h"
#include "Camera.h"
#include "Test/Test.h"

class CEngine : public TSingleton<CEngine>
{
	friend class TSingleton<CEngine>;

public:
	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);
	void Update(float DeltaTime);
	FRenderDevice& GetRenderDevice() { return RenderDevice; }
	CCamera& GetCamera() { return Camera; }

	static void DrawPrimitive(const CPrimitive& Primitive);

private:
	CEngine();
	~CEngine();

	FRenderDevice RenderDevice;
	FPipeline Pipeline;
	CCamera Camera;
	CTest Test;
};

