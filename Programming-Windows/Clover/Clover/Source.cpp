#include <Windows.h>
#include <math.h>

#define TWOPI (2 * 3.14159)
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdSHow)
{
	static TCHAR szAppName[] = "Clover";

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
	HCURSOR hCursor;
	PAINTSTRUCT ps;
	static HRGN hRgnClip;
	static int cxClient, cyClient;
	double fAngle, fRadius;
	HRGN hRgnTemp[6];

	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		hCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
		ShowCursor(TRUE);

		if (hRgnClip)
			DeleteObject(hRgnClip);

		hRgnTemp[0] = CreateEllipticRgn(0, cyClient / 3, cxClient / 2, 2 * cyClient / 3);
		hRgnTemp[1] = CreateEllipticRgn(cxClient / 2, cyClient / 3, cxClient, 2 * cyClient / 3);
		hRgnTemp[2] = CreateEllipticRgn(cxClient / 3, 0, 2 * cxClient / 3, cyClient / 2);
		hRgnTemp[3] = CreateEllipticRgn(cxClient / 3, cyClient / 2, 2 * cxClient / 3, cyClient);
		hRgnTemp[4] = CreateRectRgn(0, 0, 1, 1);
		hRgnTemp[5] = CreateRectRgn(0, 0, 1, 1);
		hRgnClip = CreateRectRgn(0, 0, 1, 1);

		CombineRgn(hRgnTemp[4], hRgnTemp[0], hRgnTemp[1], RGN_OR);
		CombineRgn(hRgnTemp[5], hRgnTemp[2], hRgnTemp[3], RGN_OR);
		CombineRgn(hRgnClip, hRgnTemp[4], hRgnTemp[5], RGN_XOR);

		for (int i = 0; i < 6; i++)
			DeleteObject(hRgnTemp[i]);

		SetCursor(hCursor);
		ShowCursor(FALSE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);
		SelectClipRgn(hdc, hRgnClip);
		fRadius = _hypot(cxClient / 2.0, cyClient / 2.0);
		for (fAngle = 0.0; fAngle < TWOPI; fAngle += TWOPI / 360)
		{
			MoveToEx(hdc, 0, 0, NULL);
			LineTo(hdc, (int)fRadius * cos(fAngle) + 0.5, (int)(-fRadius * sin(fAngle) + 0.5));
		}
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

