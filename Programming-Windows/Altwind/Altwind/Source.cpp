#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdSHow)
{
	static TCHAR szAppName[] = "AltWindow";

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

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	HBRUSH hBrush;
	PAINTSTRUCT ps;
	static int cxClient, cyClient;
	static POINT apt[3];
	
	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		apt[0].x = cxClient / 2;
		apt[0].y = 0;
		apt[1].x = cxClient / 5;
		apt[1].y = cyClient;
		apt[2].x = cxClient * 4 / 5;
		apt[2].y = cyClient;
		Polygon(hdc, apt, 3);
		DeleteObject(hBrush);

		hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 0));
		SelectObject(hdc, hBrush);
		apt[0].x = cxClient / 4;
		apt[0].y = 0;
		apt[1].x = 0;
		apt[1].y = cyClient;
		apt[2].x = cxClient / 2;
		apt[2].y = cyClient;
		Polygon(hdc, apt, 3);
		DeleteObject(hBrush);

		hBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 255));
		SelectObject(hdc, hBrush);
		apt[0].x = cxClient * 3 / 4;
		apt[0].y = 0;
		apt[1].x = cxClient / 2;
		apt[1].y = cyClient;
		apt[2].x = cxClient;
		apt[2].y = cyClient;
		Polygon(hdc, apt, 3);
		DeleteObject(hBrush);
		DeleteDC(hdc);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

