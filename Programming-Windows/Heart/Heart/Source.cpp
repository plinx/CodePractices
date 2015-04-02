#include "Header.h"
#include <ObjIdl.h>
#include <gdiplus.h>
#include <math.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
	for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Bitmap *bitmap = new Bitmap(1024, 1024);
	INT width = 1024;
	INT height = 1024;
	Color color;

	for (INT sy = 0; sy < height; ++sy)
	{
		float z = 1.5f - sy * 3.0f / height;
		for (INT sx = 0; sx < width; ++sx)
		{
			float x = sx * 3.0f / width - 1.5f;
			float v = f(x, 0.0f, z);
			int r = 0;
			if (v <= 0.0f) {
				float y0 = h(x, z);
				float ny = 0.001f;
				float nx = h(x + ny, z) - y0;
				float nz = h(x, z + ny) - y0;
				float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
				float d = (nx + ny - nz) / sqrtf(3) * nd * 0.5f + 0.5f;
				r = (int)(d * 255.0f);
			}
			color.SetValue(Color::MakeARGB(
				(BYTE)(255),
				(BYTE)(r),
				(BYTE)(0),
				(BYTE)(0)
				));
			bitmap->SetPixel(sx, sy, color);
		}
	}

	graphics.DrawImage(bitmap, 0, 0, 512, 512);

	delete bitmap;
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wndClass;
	GdiplusStartupInput gdiInput;
	ULONG_PTR gdiToken;

	// Initial GDI+
	GdiplusStartup(&gdiToken, &gdiInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("Heart!");

	RegisterClass(&wndClass);

	hwnd = CreateWindow(
		TEXT("Heart!"),   // window class name
		TEXT("Heart!"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		//CW_USEDEFAULT,            // initial x size
		512,
		//CW_USEDEFAULT,            // initial y size
		512,
		NULL,                     // parent window handle
		NULL,                     // window menu handle
		hInstance,                // program instance handle
		NULL);                    // creation parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiToken);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		OnPaint(hdc);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, msg, wp, lp);
	}
}

