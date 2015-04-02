#include <Windows.h>
#include <math.h>

#define NUM 1000
#define PI	3.14159

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = "SineWave";

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
		MessageBox(NULL, TEXT("Registerclass error!"), NULL, NULL);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, TEXT("Sine Wave Using PolyLine"),
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
	HDC hdc;
	PAINTSTRUCT ps;
	POINT apt[NUM];

	switch (msg)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		//MoveToEx(hdc, 0, cyClient / 2, NULL);
		//LineTo(hdc, cxClient, 0);
		//MoveToEx(hdc, 0, cyClient / 2, NULL);
		//LineTo(hdc, cxClient, cyClient / 2);

		for (int i = 0; i < NUM; i++)
		{
			apt[i].x = i*cxClient / NUM;
			apt[i].y = (int)(cyClient / 2 * (1 - sin(2 * PI * i / NUM)));
		}
		Polyline(hdc, apt, NUM);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}



