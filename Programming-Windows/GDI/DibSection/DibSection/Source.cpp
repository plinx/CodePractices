#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("DibSection");

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
		MessageBox(NULL, TEXT("Register class error!"),
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
	static int cxClient, cyClient;
	static BITMAPINFO* Info = (BITMAPINFO*)malloc(sizeof(BITMAPINFOHEADER) + 2 * sizeof(RGBQUAD));
	HDC hdc, hdcmem;
	HBITMAP hbitmap;
	PAINTSTRUCT ps;
	PBYTE pRgb, Line = NULL;
	int BytesPerLine;

	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		
		Info->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		Info->bmiHeader.biWidth = cxClient;
		Info->bmiHeader.biHeight = cyClient;
		Info->bmiHeader.biPlanes = 1;
		Info->bmiHeader.biBitCount = 24;
		Info->bmiHeader.biCompression = BI_RGB;
		Info->bmiHeader.biSizeImage = 0;
		Info->bmiHeader.biXPelsPerMeter = 0;
		Info->bmiHeader.biYPelsPerMeter = 0;
		Info->bmiHeader.biClrUsed = 0;
		Info->bmiHeader.biClrImportant = 0;

		Info->bmiColors[0].rgbBlue = 0;
		Info->bmiColors[0].rgbGreen = 0;
		Info->bmiColors[0].rgbRed = 0;
		Info->bmiColors[0].rgbReserved = 0;
		Info->bmiColors[1].rgbBlue = 255;
		Info->bmiColors[1].rgbGreen = 255;
		Info->bmiColors[1].rgbRed = 255;
		Info->bmiColors[1].rgbReserved = 255;

		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hbitmap = CreateDIBSection(NULL, Info, DIB_RGB_COLORS, (void**)&pRgb, NULL, NULL);
		BytesPerLine = cxClient * 3;

		if (BytesPerLine % 4 != 0)
			BytesPerLine += 4 - BytesPerLine % 4;
		for (float y = 0; y < cyClient; y++)
		{
			Line = pRgb;
			for (float x = 0; x < cxClient; x++)
			{
				Line[0] = 0;
				Line[1] = y / cyClient * 255;
				Line[2] = x / cxClient * 255;
				Line += 3;
			}
			pRgb += BytesPerLine;
		}

		hdcmem = CreateCompatibleDC(hdc);
		SelectObject(hdcmem, hbitmap);
		BitBlt(ps.hdc, 
			0, 0, cxClient, cyClient, 
			hdcmem, 0, 0, SRCCOPY);

		DeleteDC(hdcmem);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}