#include "Header.h"
#include <ObjIdl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	GraphicsPath path;
	Bitmap bitmap(L"zorro.jpg");
	TextureBrush tBrush(&bitmap);
	Pen pen(&tBrush, 50);

	// initial the color matrix
	ColorMatrix matrix = {
		1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.5f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	ImageAttributes attribute;
	attribute.SetColorMatrix(&matrix, ColorMatrixFlagsDefault,
		ColorAdjustTypeBitmap);


	graphics.DrawImage(&bitmap, 
		Rect(0, 0, bitmap.GetWidth(), bitmap.GetHeight()),
		0, 0, bitmap.GetWidth(), bitmap.GetHeight(),
		UnitPixel, &attribute);
	path.StartFigure();
	path.AddLine(Point(170, 145), Point(180, 150));
	path.AddLine(Point(180, 150), Point(350, 150));
	path.AddLine(Point(350, 150), Point(210, 270));
	path.AddLine(Point(210, 270), Point(370, 270));
	path.AddLine(Point(370, 270), Point(375, 275));

	pen.SetLineJoin(LineJoinMiter);
	graphics.DrawPath(&pen, &path);
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
	wndClass.lpszClassName = TEXT("Zorro!");

	RegisterClass(&wndClass);

	hwnd = CreateWindow(
		TEXT("Zorro!"),   // window class name
		TEXT("Zorro!"),  // window caption
		WS_OVERLAPPEDWINDOW,      // window style
		CW_USEDEFAULT,            // initial x position
		CW_USEDEFAULT,            // initial y position
		//CW_USEDEFAULT,            // initial x size
		555,
		//CW_USEDEFAULT,            // initial y size
		700,
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
