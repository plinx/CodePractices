#include "Header.h"
#include <ObjIdl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);

VOID OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	SolidBrush brush(Color(155, 0, 0));
	FontFamily fontFamily(L"Consolas");
	Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
	PointF pointF(50.0f, 20.0f);

	graphics.DrawString(L"Hello String", -1, &font, pointF, &brush);

}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
	HWND hwnd;
	MSG	msg;
	WNDCLASS wndClass;
	GdiplusStartupInput gdiplusInput;
	ULONG_PTR gdiplusToken;

	GdiplusStartup(&gdiplusToken, &gdiplusInput, NULL);

	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = wndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = TEXT("DrawString");

	RegisterClass(&wndClass);

	hwnd = CreateWindow(
		TEXT("DrawString"),			// window class name
		TEXT("Drawing String"),		// window caption
		WS_OVERLAPPEDWINDOW,		// window style
		CW_USEDEFAULT,				// initial x position
		CW_USEDEFAULT,				// initial y position
		CW_USEDEFAULT,				// initial x size
		CW_USEDEFAULT,				// initial y size
		NULL,						// parent window handle
		NULL,						// window menu handle
		hInstance,					// program instance handle
		NULL						// creation parameters
		);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GdiplusShutdown(gdiplusToken);
	return msg.wParam;
}

LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
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
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}
