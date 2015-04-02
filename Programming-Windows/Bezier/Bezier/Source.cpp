#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("Bezier");

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

void DrawBezier(HDC hdc, POINT apt[])
{
	PolyBezier(hdc, apt, 4);
	MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
	LineTo(hdc, apt[1].x, apt[1].y);

	MoveToEx(hdc, apt[2].x, apt[2].y, NULL);
	LineTo(hdc, apt[3].x, apt[3].y);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static POINT apt[4];
	HDC hdc;
	int cxClient, cyClient;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		apt[0].x = cxClient / 4;
		apt[0].y = cyClient / 2;
	
		apt[1].x = cxClient / 2;
		apt[1].y = cyClient / 4;

		apt[2].x = cxClient / 2;
		apt[2].y = 3 * cyClient / 4;

		apt[3].x = 3 * cxClient / 4;
		apt[3].y = cyClient / 2;
		return 0;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MOUSEMOVE:
		if (wParam & MK_LBUTTON || wParam & MK_RBUTTON)
		{
			hdc = GetDC(hwnd);
			SelectObject(hdc, GetStockObject(WHITE_PEN));
			DrawBezier(hdc, apt);

			if (wParam & MK_LBUTTON)
			{
				apt[1].x = LOWORD(lParam);
				apt[1].y = HIBYTE(lParam);
			}

			if (wParam & MK_RBUTTON)
			{
				apt[2].x = LOWORD(lParam);
				apt[2].y = HIBYTE(wParam);
			}

			SelectObject(hdc, GetStockObject(BLACK_PEN));
			DrawBezier(hdc, apt);
			ReleaseDC(hwnd, hdc);
		}
		return 0;
	case WM_PAINT:
		InvalidateRect(hwnd, NULL, TRUE);
		hdc = BeginPaint(hwnd, &ps);
		DrawBezier(hdc, apt);
		EndPaint(hwnd, &ps);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

