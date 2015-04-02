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

void GetLargestDisplayMode(int * pcxBitmap, int * pcyBitmap)
{
	DEVMODE devmode;
	int iModeNum = 0;
	*pcxBitmap = *pcyBitmap = 0;
	ZeroMemory(&devmode, sizeof(DEVMODE));
	devmode.dmSize = sizeof(DEVMODE);
	while (EnumDisplaySettings(NULL, iModeNum++, &devmode))
	{
		*pcxBitmap = max(*pcxBitmap, (int)devmode.dmPelsWidth);
		*pcyBitmap = max(*pcyBitmap, (int)devmode.dmPelsHeight);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//static int cxClient, cyClient;
	static BOOL fLeftButtonDown, fRightButtonDown;
	static HBITMAP hBitmap;
	static HDC hdcMem;
	static int cxBitmap, cyBitmap, cxClient, cyClient, xMouse, yMouse;
	BITMAPINFOHEADER *bmih = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
	BYTE *pbits;
	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		GetLargestDisplayMode(&cxBitmap, &cyBitmap);
		hdc = GetDC(hwnd);
		//hBitmap = CreateCompatibleBitmap(hdc, cxBitmap, cyBitmap);
		hBitmap = CreateDIBSection(NULL, (BITMAPINFO *)&bmih, 0, (void**)&pbits, NULL, 0);
		//GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		hdcMem = CreateCompatibleDC(hdc);
		SelectObject(hdcMem, hBitmap);
		ReleaseDC(hwnd, hdc);
		PatBlt(hdcMem, 0, 0, cxBitmap, cyBitmap, WHITENESS);
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		bmih->biSize = sizeof(BITMAPINFOHEADER);
		bmih->biWidth = cxClient;
		bmih->biHeight = cyClient;
		bmih->biPlanes = 1;
		bmih->biBitCount = 24;
		bmih->biCompression = BI_RGB;
		bmih->biSizeImage = 0;
		bmih->biXPelsPerMeter = 0;
		bmih->biYPelsPerMeter = 0;
		bmih->biClrUsed = 0;
		bmih->biClrImportant = 0;

		return 0;
	case WM_LBUTTONDOWN:
		if (!fRightButtonDown)
			SetCapture(hwnd);
		xMouse = LOWORD(lParam);
		yMouse = HIWORD(lParam);
		fLeftButtonDown = TRUE;
		return 0;
	case WM_LBUTTONUP:
		if (fLeftButtonDown)
			SetCapture(NULL);
		fLeftButtonDown = FALSE;
		return 0;
	case WM_RBUTTONDOWN:
		if (!fLeftButtonDown)
			SetCapture(hwnd);
		xMouse = LOWORD(lParam);
		yMouse = HIWORD(lParam);
		fRightButtonDown = TRUE;
		return 0;
	case WM_RBUTTONUP:
		if (fRightButtonDown)
			SetCapture(NULL);
		fRightButtonDown = TRUE;
		return 0;
	case WM_MOUSEMOVE:
		if (!fLeftButtonDown && !fRightButtonDown)
			return 0;

		hdc = GetDC(hwnd);
		SelectObject(hdc,
			GetStockObject(fLeftButtonDown ? BLACK_PEN :
			WHITE_PEN));
		SelectObject(hdcMem,
			GetStockObject(fLeftButtonDown ? BLACK_PEN :
			WHITE_PEN));
		MoveToEx(hdc, xMouse, yMouse, NULL);
		MoveToEx(hdcMem, xMouse, yMouse, NULL);
		xMouse = (short)LOWORD(lParam);
		yMouse = (short)HIWORD(lParam);
		LineTo(hdc, xMouse, yMouse);
		LineTo(hdcMem, xMouse, yMouse);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		BitBlt(hdc, 0, 0, cxClient, cyClient,
			hdcMem, 0, 0, SRCCOPY);
		DeleteObject(hBitmap);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

