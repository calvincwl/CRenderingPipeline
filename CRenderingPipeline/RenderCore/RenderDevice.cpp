// Copyright 2017 Calvin Lee. All Rights Reserved.

#include "RenderDevice.h"
#include "Engine/Engine.h"
#include "Windows/WinApp.h"

template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

FRenderDevice::FRenderDevice()
{
	WinApp = new FWinApp();
	D2DFactory = NULL;
	RenderTarget = NULL;
}


FRenderDevice::~FRenderDevice()
{
	SafeRelease(&D2DFactory);
	SafeRelease(&RenderTarget);
}

bool FRenderDevice::Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	if (!WinApp->Initialize(HInstance, CmdShow, Width, Height)) { return false; }

	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &D2DFactory);
	if (FAILED(hr))
	{
		MessageBox(WinApp->GetWindow(), L"Create D2D factory failed!", L"Error", 0);
		return false;
	}

	// Obtain the size of the drawing area.
	RECT rc;
	GetClientRect(WinApp->GetWindow(), &rc);
	WindowSize = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);
	BufferSize = WindowSize.width * WindowSize.height * sizeof(DWORD);

	D2D1_PIXEL_FORMAT PixelFormat = D2D1::PixelFormat(
		DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE);

	D2D1_RENDER_TARGET_PROPERTIES RTProperties = D2D1::RenderTargetProperties();
	RTProperties.pixelFormat = PixelFormat;

	// Create a Direct2D render target
	hr = D2DFactory->CreateHwndRenderTarget(RTProperties, D2D1::HwndRenderTargetProperties(
		WinApp->GetWindow(), D2D1::SizeU(WindowSize.width, WindowSize.height)), &RenderTarget);
	if (FAILED(hr))
	{
		MessageBox(WinApp->GetWindow(), L"Create render target failed!", L"Error", 0);
		return false;
	}

	// ´´½¨Î»Í¼
	D2D1_BITMAP_PROPERTIES BMPProperties = {
		PixelFormat,
		(float)WindowSize.width,
		(float)WindowSize.height
	};
	long pitch = WindowSize.width;
	PixelBuffer = new DWORD[WindowSize.width * WindowSize.height];
	memset(PixelBuffer, 0, WindowSize.width * WindowSize.height * sizeof(DWORD));
	RenderTarget->CreateBitmap(WindowSize, PixelBuffer, pitch, &BMPProperties, &Bitmap);

	return true;
}

void FRenderDevice::SetPixel(UINT32 X, UINT32 Y, DWORD Color)
{
	if (X < WindowSize.width && Y < WindowSize.height)
	{
		PixelBuffer[(WindowSize.height - 1 - Y) * WindowSize.width + X] = Color;
	}
}

void FRenderDevice::Clear()
{
	memset(PixelBuffer, 0, WindowSize.width * WindowSize.height * sizeof(DWORD));
}

void FRenderDevice::Draw()
{
	RenderTarget->BeginDraw();
	RenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

	static D2D1_RECT_U rc = D2D1::RectU(0, 0, WindowSize.width, WindowSize.height);
	Bitmap->CopyFromMemory(&rc, PixelBuffer, WindowSize.width * sizeof(DWORD));
	RenderTarget->DrawBitmap(Bitmap, D2D1::RectF(0.0f, 0.0f, (FLOAT)WindowSize.width, (FLOAT)WindowSize.height));

	RenderTarget->EndDraw();
}
