// CLRenderingPipeline.cpp : Defines the entry point for the application.
//

#include <windows.h>
#include <tchar.h>
#include "Engine/Engine.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	// Time
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f / (float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

    // Perform application initialization:
    if (!CEngine::Instance().Initialize(hInstance, nCmdShow, 1024, 768))
    {
        return FALSE;
    }

    MSG msg;

    // Main message loop:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) { break; }

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);

			float DeltaTime = (currTimeStamp - prevTimeStamp) * secsPerCnt;
			prevTimeStamp = currTimeStamp;
			CEngine::Instance().Update(DeltaTime);
		}
	}

    return (int) msg.wParam;
}
