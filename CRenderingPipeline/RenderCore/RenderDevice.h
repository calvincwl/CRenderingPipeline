// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>

class FWinApp;

class FRenderDevice
{
	friend class CLEngine;

public:
	int GetWindowWidth() const { return WindowWidth; }
	int GetWindowHeight() const { return WindowHeight; }
	void SetPixel(int X, int Y, DWORD Color);
	void Clear();
	void Draw();

private:
	FRenderDevice();
	~FRenderDevice();

	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);

	FWinApp* WinApp;
	int WindowWidth;
	int WindowHeight;
	HDC WindowDC;	// �����豸�������
	HDC CompatibleDC;	// ���ڼ����豸�������
	HBITMAP Bitmap;	// ��Ⱦλͼ���
	DWORD* PixelBuffer;	// ����Buffer
	DWORD BufferSize;
};

