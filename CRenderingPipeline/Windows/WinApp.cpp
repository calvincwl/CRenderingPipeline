// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "WinApp.h"
#include <tchar.h>



FWinApp::FWinApp()
	: Title(_T("CLRenderingPipeline"))
	, WindowClass(_T("CLRenderingPipeline"))
{
}


FWinApp::~FWinApp()
{
}

//************************************
// Method:    Initialize
// FullName:  WinApp::Initialize
// Access:    public 
// Returns:   bool
// Qualifier: Saves instance handle and creates main window
// Parameter: HINSTANCE HInstance
// Parameter: int CmdShow
// Parameter: int Width
// Parameter: int Height
//************************************
bool FWinApp::Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	RegisterClass(HInstance);

	return InitInstance(HInstance, CmdShow, Width, Height);
}

//************************************
// Method:    RegisterClass
// FullName:  WinApp::RegisterClass
// Access:    private 
// Returns:   ATOM
// Qualifier: Registers the window class.
// Parameter: HINSTANCE HInstance
//************************************
ATOM FWinApp::RegisterClass(HINSTANCE HInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = HInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = WindowClass.c_str();
	wcex.hIconSm = nullptr;

	return RegisterClassExW(&wcex);
}

//************************************
// Method:    InitInstance
// FullName:  WinApp::InitInstance
// Access:    private 
// Returns:   bool
// Qualifier: Saves instance handle and creates main window
// Parameter: HINSTANCE HInstance
// Parameter: int CmdShow
// Parameter: int Width
// Parameter: int Height
//************************************
bool FWinApp::InitInstance(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	HWnd = CreateWindow(WindowClass.c_str(), Title.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, Width, Height, nullptr, nullptr, HInstance, nullptr);

	if (!HWnd)
	{
		return false;
	}

	ShowWindow(HWnd, CmdShow);
	UpdateWindow(HWnd);

	return true;
}

//************************************
// Method:    WndProc
// FullName:  WinApp::WndProc
// Access:    public 
// Returns:   LRESULT CALLBACK
// Qualifier: Processes messages for the main window.
// Parameter: HWND HWnd
// Parameter: UINT Message
// Parameter: WPARAM WParam
// Parameter: LPARAM LParam
//************************************
LRESULT CALLBACK FWinApp::WndProc(HWND HWnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
	switch (Message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(HWnd, Message, WParam, LParam);
	}
	return 0;
}
