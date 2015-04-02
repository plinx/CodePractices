#include "packedib.h"
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szAppName[] = TEXT("ShowDib3");
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szAppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Register class error!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, TEXT("Show Dib #3: Native Palette"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
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
	static BITMAPINFO *pPackedDib;
	static HPALETTE hPalatte;
	static int cxClient, cyClient;
	static OPENFILENAME ofn;
	static TCHAR szFileName[MAX_PATH], szTitleName[MAX_PATH];
	static TCHAR szFilter[] = TEXT("Bitmap Files (*.BMP)\0*.*\0\0");
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = hwnd;
		ofn.hInstance = NULL;
		ofn.lpstrFile = szFilter;
		ofn.nMaxCustFilter = 0;
		ofn.nFilterIndex = 0;
		ofn.lpstrFile = szFileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFileTitle = szTitleName;
		ofn.nMaxFileTitle = MAX_PATH;
		ofn.lpstrInitialDir = NULL;
		ofn.lpstrTitle = NULL;
		ofn.Flags = 0;
		ofn.nFileOffset = 0;
		ofn.nFileExtension = 0;
		ofn.lpstrDefExt = TEXT("bmp");
		ofn.lCustData = 0;
		ofn.lpfnHook = NULL;
		ofn.lpTemplateName = NULL;
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILE_OPEN:
			if (!GetOpenFileName(&ofn))
				return 0;
			if (pPackedDib)
			{
				free(pPackedDib);
				pPackedDib = NULL;
			}
			if (hPalatte)
			{
				DeleteObject(hPalatte);
				hPalatte = NULL;
			}

			SetCursor(LoadCursor(NULL, IDC_WAIT));
			ShowCursor(TRUE);

			pPackedDib = PackedDibLoad(szFileName);
			ShowCursor(FALSE);
			SetCursor(LoadCursor(NULL, IDC_ARROW));
			if (pPackedDib)
			{
				hPalatte = PackedDibCreatePalette(pPackedDib);
			}
			else
			{
				MessageBox(hwnd, TEXT("Cannot load DIB file"),
					szAppName, 0);
			}
			InvalidateRect(hwnd, NULL, TRUE);
			return 0;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (hPalatte)
		{
			SelectPalette(hdc, hPalatte, FALSE);
			RealizePalette(hdc);
		}

		if (pPackedDib)
			SetDIBitsToDevice(
			hdc, 0, 0,
			PackedDibGetWidth(pPackedDib),
			PackedDibGetHeight(pPackedDib),
			0, 0, 0,
			PackedDibGetWidth(pPackedDib),
			PackedDibGetBitsPtr(pPackedDib),
			pPackedDib, DIB_RGB_COLORS);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_QUERYNEWPALETTE:
		if (!hPalatte)
			return FALSE;
		hdc = GetDC(hwnd);
		SelectPalette(hdc, hPalatte, FALSE);
		RealizePalette(hdc);
		InvalidateRect(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		return TRUE;
	case WM_PALETTECHANGED:
		if (!hPalatte || (HWND)wParam == hwnd)
			break;

		hdc = GetDC(hwnd);
		SelectPalette(hdc, hPalatte, FALSE);
		RealizePalette(hdc);
		UpdateColors(hdc);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		if (pPackedDib)
			free(pPackedDib);
		if (hPalatte)
			DeleteObject(hPalatte);

		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}