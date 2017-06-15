#include "RenderDevice.h"
#include <wingdi.h>
#include "Engine/Engine.h"
#include "Windows/WinApp.h"



FRenderDevice::FRenderDevice()
{
	WinApp = new FWinApp();
}


FRenderDevice::~FRenderDevice()
{
	DeleteDC(CompatibleDC);
	ReleaseDC(WinApp->GetWindow(), WindowDC);
	delete WinApp;
}

bool FRenderDevice::Initialize(HINSTANCE HInstance, int CmdShow, int Width, int Height)
{
	if (!WinApp->Initialize(HInstance, CmdShow, Width, Height)) { return false; }

	WindowWidth = Width;
	WindowHeight = Height;
	BufferSize = WindowWidth * WindowHeight * sizeof(DWORD);

	WindowDC = GetWindowDC(WinApp->GetWindow());
	CompatibleDC = CreateCompatibleDC(WindowDC);

	// 配置BITMAPINFO信息
	BITMAPINFO Bmpinfo;
	Bmpinfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	Bmpinfo.bmiHeader.biWidth = WindowWidth;
	Bmpinfo.bmiHeader.biHeight = WindowHeight;
	Bmpinfo.bmiHeader.biPlanes = 1;
	Bmpinfo.bmiHeader.biBitCount = 32;
	Bmpinfo.bmiHeader.biCompression = BI_RGB;
	Bmpinfo.bmiHeader.biSizeImage = BufferSize;
	Bmpinfo.bmiHeader.biXPelsPerMeter = 0;
	Bmpinfo.bmiHeader.biClrImportant = 0;
	Bmpinfo.bmiHeader.biClrUsed = 0;

	// 申请内存, 无需手动释放
	Bitmap = CreateDIBSection(CompatibleDC, &Bmpinfo, DIB_RGB_COLORS, (void**)&PixelBuffer, NULL, 0);

	return true;
}

void FRenderDevice::SetPixel(int X, int Y, DWORD Color)
{
	if (X < WindowWidth && Y < WindowHeight)
	{
		PixelBuffer[(WindowHeight - 1 - Y) * WindowWidth + X] = Color;
	}
}

void FRenderDevice::Clear()
{
	ZeroMemory(PixelBuffer, BufferSize);
}

void FRenderDevice::Draw()
{
	HGDIOBJ OldSel = SelectObject(CompatibleDC, Bitmap);

	// 将CompatibleDC的数据复制到屏幕显示DC中
	BitBlt(WindowDC, 0, 0, WindowWidth, WindowHeight, CompatibleDC, 0, 0, SRCCOPY);

	SelectObject(CompatibleDC, OldSel);
}
