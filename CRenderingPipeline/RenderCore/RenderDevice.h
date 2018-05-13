// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>
#include <d2d1.h>

class FWinApp;

class FRenderDevice
{
	friend class CEngine;

public:
	int GetWindowWidth() const { return WindowSize.width; }
	int GetWindowHeight() const { return WindowSize.height; }
	void SetPixel(UINT32 X, UINT32 Y, DWORD Color);
	void Clear();
	void Draw();

private:
	FRenderDevice();
	~FRenderDevice();

	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);

	FWinApp* WinApp;
	D2D1_SIZE_U WindowSize;
	ID2D1Factory* D2DFactory;
	ID2D1HwndRenderTarget* RenderTarget;
	ID2D1Bitmap* Bitmap;	// Î»Í¼
	DWORD* PixelBuffer;	// ÏñËØBuffer
	DWORD BufferSize;
};

