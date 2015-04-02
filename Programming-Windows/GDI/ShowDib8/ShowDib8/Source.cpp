#include "packedib.h"
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szAppName[] = TEXT("ShowDib8");
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
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szAppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Register class error."),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, szAppName,
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
	static HBITMAP hBitmap;
	static HPALETTE hPalette;
	static int cxClient, cyClient;
	static OPENFILENAME ofn;
	static PBYTE pBits;
	static TCHAR szFileName[MAX_PATH], szTitleName[MAX_PATH];
	static TCHAR szFilter[] = TEXT("BitMap files (*.BMP)\0*.bmp\0");
	
	BITMAP bitmap;
	BITMAPINFO * pPackedDib;
	HDC hdc, hdcMem;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = hwnd;
		ofn.hInstance = NULL;
		ofn.lpstrFile = szFilter;
		ofn.lpstrCustomFilter = NULL;
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
		
		hdc = GetDC(hwnd);
		hPalette = CreateHalftonePalette(hdc);
		ReleaseDC(hwnd, hdc);
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
			if (hBitmap)
			{
				DeleteObject(hBitmap);
				hBitmap = NULL;
			}

			if (hPalette)
			{
				DeleteObject(hPalette);
				hPalette = NULL;
			}

			SetCursor(LoadCursor(NULL, IDC_WAIT));
			ShowCursor(TRUE);
			pPackedDib = PackedDibLoad(szFileName);
			ShowCursor(FALSE);
			SetCursor(LoadCursor(NULL, IDC_ARROW));

			if (pPackedDib)
			{
				hBitmap = CreateDIBSection(NULL, pPackedDib,
					DIB_RGB_COLORS, (void **)&pBits, NULL, 0);
				CopyMemory(pBits, PackedDibGetBitsPtr(pPackedDib),
					PackedDibGetBitsSize(pPackedDib));
				hPalette = PackedDibCreatePalette(pPackedDib);
				free(pPackedDib);
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
		if (hPalette)
		{
			SelectPalette(hdc, hPalette, FALSE);
			RealizePalette(hdc);
		}

		if (hBitmap)
		{
			GetObject(hBitmap, sizeof(BITMAP), &bitmap);
			hdcMem = CreateCompatibleDC(hdc);
			SelectObject(hdcMem, hBitmap);
			BitBlt(
				hdc, 0, 0,
				bitmap.bmWidth, bitmap.bmHeight,
				hdcMem, 0, 0,
				SRCCOPY);
			DeleteDC(hdcMem);
		}
		EndPaint(hwnd, &ps);
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
		return 0;
	case WM_DESTROY:
		if (hBitmap)
			DeleteObject(hBitmap);

		if (hPalette)
			DeleteObject(hPalette);

		PostQuitMessage(0);
		return 0;		
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);

}