#include <Windows.h>
#include "bounce.h"
/*
extern HPALETTE CreateRountine(HWND);
extern void PaintRountine(HDC, int, int);
extern void TimerRountine(HDC, HPALETTE);
extern void DestroyRountine(HWND, HPALETTE);
*/

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static TCHAR szAppName[] = TEXT("Bounce");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{

	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Registerclass error!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, szAppName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HPALETTE hPalette;
	static int cxClient, cyClient;
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		hPalette = CreateRountine(hwnd);
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SelectPalette(hdc, hPalette, FALSE);
		RealizePalette(hdc);
		PaintRountine(hdc, cxClient, cyClient);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_TIMER:
		hdc = GetDC(hwnd);
		SelectPalette(hdc, hPalette, FALSE);
		TimerRountine(hdc, hPalette);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_QUERYNEWPALETTE:
		if (!hPalette)
			return FALSE;
		hdc = GetDC(hwnd);
		SelectPalette(hdc, hPalette, FALSE);
		RealizePalette(hdc);
		InvalidateRect(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		return TRUE;
	case WM_PALETTECHANGED:
		if (!hPalette || (HWND)wParam == hwnd)
			break;
		hdc = GetDC(hwnd);
		SelectPalette(hdc, hPalette, FALSE);
		RealizePalette(hdc);
		UpdateColors(hdc);

		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		DestroyRountine(hwnd, hPalette);
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
