// Copyright 2017 Calvin Lee. All Rights Reserved.

#pragma once

#include <windows.h>
#include <string>

class FWinApp
{
	friend class FRenderDevice;

public:
	HWND GetWindow() const { return HWnd; }

private:
	FWinApp();
	~FWinApp();

	bool Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height);
	ATOM RegisterClass(HINSTANCE HInstance);
	bool InitInstance(HINSTANCE HInstance, int CmdShow, int Width, int Height);
	static LRESULT CALLBACK WndProc(HWND HWnd, UINT Message, WPARAM WParam, LPARAM LParam);

	HWND HWnd;
	std::wstring Title;
	std::wstring WindowClass;
};

