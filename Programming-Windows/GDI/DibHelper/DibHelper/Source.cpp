#include "DibHelp.h"

static HDC hdcMem;
static HBITMAP hBitmap;
static int cxBitmap, cyBitmap, cxClient, cyClient, xMouse, yMouse;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Render(HWND hwnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIinstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("DibHelper");

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

	hwnd = CreateWindow(szAppName, szAppName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Render(hwnd);
		}
	}

	return msg.wParam;
}

void Render(HWND hwnd)
{
	HBRUSH hBrush;
	HDC hdc;
	RECT rect;
	static POINT apt[3];

	if (cxClient == 0 || cyClient == 0)
		return;

	hdc = GetDC(hwnd);
	hBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

	BitBlt(hdc, 0, 0, cxClient, cyClient,
		hdcMem, 0, 0, SRCCOPY);
	
	ReleaseDC(hwnd, hdc);
	DeleteObject(hBrush);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	BITMAPINFOHEADER *pbmih = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
	static BOOL fLeftButtonDown, fRightButtonDown;
	static HDIB hdib;

	HDC hdc;
	PAINTSTRUCT ps;
	static PDIBSTRUCT pdib;
	BYTE *pBits;

	switch (msg)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		//hdib = DibCreate(cxClient, cyClient, 24);
		//pdib = (PDIBSTRUCT)hdib;
		//pdib = (PDIBSTRUCT)malloc(sizeof(DIBSTRUCT));
		//pdib->hBitmap = CreateCompatibleBitmap(hdc, cxBitmap, cyBitmap);
		//hBitmap = CreateCompatibleBitmap(hdc, cxBitmap, cyBitmap);
		hBitmap = CreateDIBSection(NULL, (BITMAPINFO *)&pbmih, 0, (void**)&pBits, NULL, 0);
		hdcMem = CreateCompatibleDC(hdc);

		SelectObject(hdcMem, hBitmap);
		
		//PatBlt(hdcMem, 0, 0, cxBitmap, cyBitmap, WHITENESS);
		ReleaseDC(hwnd, hdc);
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		pbmih->biSize = sizeof(BITMAPINFOHEADER);
		pbmih->biWidth = cxClient;
		pbmih->biHeight = cyClient;
		pbmih->biPlanes = 1;
		pbmih->biBitCount = 24;
		pbmih->biCompression = BI_RGB;
		pbmih->biSizeImage = 0;
		pbmih->biXPelsPerMeter = 0;
		pbmih->biYPelsPerMeter = 0;
		pbmih->biClrUsed = 0;
		pbmih->biClrImportant = 0;

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
		fRightButtonDown = FALSE;
		return 0;
	case WM_MOUSEMOVE:
		if (!fLeftButtonDown && !fRightButtonDown)
			return 0;
		hdc = GetDC(hwnd);
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		SelectObject(hdcMem, GetStockObject(BLACK_PEN));
		
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
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		if (hdib)
			DibDelete(hdib);
		DeleteDC(hdcMem);
		DeleteObject(hBitmap);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}