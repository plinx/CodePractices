#include <windows.h>
#include <D2D1.h>

#pragma comment(lib, "d2d1.lib")

#define SAFE_RELEASE(P) if(P){P->Release() ; P = NULL ;}

VOID DrawRectangle(HWND hwnd)
{
	ID2D1Factory*			factory = NULL;	// Direct2D factory
	ID2D1HwndRenderTarget*	target = NULL;	// Render target
	ID2D1SolidColorBrush*	brush = NULL;	// A black brush, reflect the line color
	HRESULT hr;

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (FAILED(hr))
	{
		MessageBox(hwnd, "Create D2D factory failed!", "Error", 0);
		return;
	}

	// Obtain the size of the drawing area
	RECT rc;
	GetClientRect(hwnd, &rc);

	// Create a Direct2D render target
	hr = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
		hwnd,
		D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)
		),
		&target
		);
	if (FAILED(hr))
	{
		MessageBox(hwnd, "Create render target failed!", "Error", 0);
		return;
	}

	// Create a brush
	hr = target->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Black),
		&brush
		);
	if (FAILED(hr))
	{
		MessageBox(hwnd, "Create brush failed!", "Error", 0);
		return;
	}

	target->BeginDraw();

	// Clear background color to White
	target->Clear(D2D1::ColorF(D2D1::ColorF::White));

	// Draw Rectangle
	target->DrawRectangle(
		D2D1::RectF(100.f, 100.f, 500.f, 500.f),
		brush);

	target->DrawLine(
		D2D1::Point2F(100.f, 100.f),
		D2D1::Point2F(500.f, 500.f),
		brush);

	target->DrawRoundedRectangle(
		D2D1::RoundedRect(D2D1::Rect(120.f, 120.f, 480.f, 480.f), 20, 30),
		brush);

	target->DrawEllipse(
		D2D1::Ellipse(D2D1::Point2F(300.f, 300.f), 100.f, 50.f),
		brush);
	
	target->DrawEllipse(
		D2D1::Ellipse(D2D1::Point2F(300.f, 300.f), 50.f, 50.f),
		brush);

	target->DrawLine(
		D2D1::Point2F(100.f, 500.f),
		D2D1::Point2F(300.f, 100.f),
		brush);
	target->DrawLine(
		D2D1::Point2F(300.f, 100.f),
		D2D1::Point2F(500.f, 300.f),
		brush);
	target->DrawLine(
		D2D1::Point2F(500.f, 300.f),
		D2D1::Point2F(100.f, 500.f),
		brush);

	hr = target->EndDraw();
	if (FAILED(hr))
	{
		MessageBox(NULL, "Draw failed!", "Error", 0);
		return;
	}
	
	SAFE_RELEASE(target);
	SAFE_RELEASE(brush);
	SAFE_RELEASE(factory);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case   WM_PAINT:
		DrawRectangle(hwnd);
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			SendMessage(hwnd, WM_CLOSE, 0, 0);
			break;
		default:
			break;
		}
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{

	WNDCLASSEX winClass;

	winClass.lpszClassName = "Direct2D";
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = WndProc;
	winClass.hInstance = hInstance;
	winClass.hIcon = NULL;
	winClass.hIconSm = NULL;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = NULL;
	winClass.lpszMenuName = NULL;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;

	if (!RegisterClassEx(&winClass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), "error", MB_ICONERROR);
		return 0;
	}

	HWND hwnd = CreateWindowEx(NULL,
		"Direct2D",					// window class name
		"Draw Rectangle",			// window caption
		WS_OVERLAPPEDWINDOW, 		// window style
		CW_USEDEFAULT,				// initial x position
		CW_USEDEFAULT,				// initial y position
		600,						// initial x size
		600,						// initial y size
		NULL,						// parent window handle
		NULL,						// window menu handle
		hInstance,					// program instance handle
		NULL);						// creation parameters

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	MSG    msg;
	ZeroMemory(&msg, sizeof(msg));

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
