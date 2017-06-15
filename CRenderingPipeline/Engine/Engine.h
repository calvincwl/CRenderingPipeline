// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>
#include "Utils/Singleton.h"
#include "RenderCore/RenderDevice.h"

class CEngine : public TSingleton<CEngine>
{
	friend class TSingleton<CEngine>;

public:
	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);
	void Update(float DeltaTime);

private:
	CEngine();
	~CEngine();

	FRenderDevice RenderDevice;
};

