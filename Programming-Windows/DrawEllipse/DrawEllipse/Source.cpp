#include "Header.h"
#include <ObjIdl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	SolidBrush brush(Color(100, 0, 0, 255));
	Pen pen(Color(255, 0, 0, 0), 1);
	Pen anti_pen1(Color(100, 0, 0, 0), 2);
	Rect rect(100, 100, 300, 300);

	graphics.DrawEllipse(&pen, rect);
	pen.SetAlignment(PenAlignmentInset);
	graphics.DrawEllipse(&anti_pen1, rect);
	graphics.FillEllipse(&brush, rect);

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
		703,
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