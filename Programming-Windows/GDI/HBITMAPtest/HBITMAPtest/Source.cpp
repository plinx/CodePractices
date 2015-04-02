#include <Windows.h>
#include <stdlib.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawRectangle(HWND);
int cxClient, cyClient;
BITMAPINFOHEADER bmih;
BITMAPINFO * pbmi;
BYTE * pBits;
HDC hdc, hdcMem;
HBITMAP hBitmap;
HBRUSH hBrush;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdSHow)
{
	static TCHAR szAppName[] = "Randrect";

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
		MessageBox(NULL, TEXT("Register class error."),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, szAppName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdSHow);
	UpdateWindow(hwnd);

	hdc = GetDC(hwnd);
	hdcMem = CreateCompatibleDC(hdc);
	hBitmap = CreateDIBSection(NULL, (BITMAPINFO *)&bmih, 0, (void **)&pBits, NULL, 0);
	SelectObject(hdcMem, hBitmap);
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.wParam == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			DrawRectangle(hwnd);
		}
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		bmih.biSize = sizeof(BITMAPINFOHEADER);
		bmih.biWidth = cxClient;
		bmih.biHeight = cyClient;
		bmih.biPlanes = 1;
		bmih.biBitCount = 24;
		bmih.biCompression = BI_RGB;
		bmih.biSizeImage = 0;
		bmih.biXPelsPerMeter = 0;
		bmih.biYPelsPerMeter = 0;
		bmih.biClrUsed = 0;
		bmih.biClrImportant = 0;
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		DeleteDC(hdcMem);
		DeleteObject(hBitmap);
		DeleteObject(hBrush);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void DrawRectangle(HWND hwnd)
{
	RECT rect;

	if (cxClient == 0 || cyClient == 0)
		return;

	SetRect(&rect, rand() % cxClient, rand() % cyClient,
		rand() % cxClient, rand() % cyClient);

	hdc = GetDC(hwnd);
	//hBitmap = CreateCompatibleBitmap(hdc, cxClient, cyClient);
	hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	FillRect(hdcMem, &rect, hBrush);
	BitBlt(hdc, 0, 0, cxClient, cyClient,
		hdcMem, 0, 0, SRCCOPY);
	
	ReleaseDC(hwnd, hdc);
}

