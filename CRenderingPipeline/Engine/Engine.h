// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>
#include "Utils/Singleton.h"
#include "RenderCore/RenderDevice.h"

class CLEngine : public TSingleton<CLEngine>
{
	friend class TSingleton<CLEngine>;

public:
	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);
	void Update(float DeltaTime);

private:
	CLEngine();
	~CLEngine();

	FRenderDevice RenderDevice;
};

