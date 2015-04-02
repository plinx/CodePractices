#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstacne,
	PSTR csCmdLine, int iCmdShow)
{
	static TCHAR AppName[] = TEXT("Bitblt");
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = AppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			AppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		AppName, TEXT("Bitblt demo"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInstance, NULL);

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
	static int cxClient, cyClient, cxSrc, cySrc;
	HDC hdcClient, hdcWindow;
	int x, y;
	PAINTSTRUCT ps;
	
	switch (msg)
	{
	case WM_CREATE:
		cxSrc = GetSystemMetrics(SM_CXSIZEFRAME) + GetSystemMetrics(SM_CXSIZE);
		cySrc = GetSystemMetrics(SM_CYSIZEFRAME) + GetSystemMetrics(SM_CYSIZE);
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_PAINT:
		hdcClient = BeginPaint(hwnd, &ps);
		hdcWindow = GetWindowDC(hwnd);

		for (y = 0; y < cyClient; y += cySrc)
		{
			for (x = 0; x < cxClient; x += cxSrc)
			{
				BitBlt(hdcClient, x, y, cxSrc, cySrc,
					hdcWindow, 0, 0, SRCCOPY);
			}
		}

		ReleaseDC(hwnd, hdcWindow);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
