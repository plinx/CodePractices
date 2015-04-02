#include <windows.h>
#include <D2D1.h>

#pragma comment(lib, "d2d1.lib")

VOID Draw(HWND hwnd)
{
	ID2D1Factory*			factory = NULL;	// Direct2D factory
	ID2D1HwndRenderTarget*	target = NULL;
	ID2D1PathGeometry*		geometry = NULL;
	ID2D1GeometrySink*		pSink = NULL;
	ID2D1SolidColorBrush*	brush = NULL;	// A black brush, reflect the line color
	RECT rc;

	GetClientRect(hwnd, &rc);
	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	factory->CreatePathGeometry(&geometry);
	geometry->Open(&pSink);
	pSink->SetFillMode(D2D1_FILL_MODE_WINDING);
	pSink->BeginFigure(D2D1::Point2F(346, 255), D2D1_FIGURE_BEGIN_FILLED);
	
	D2D1_POINT_2F points[5] = {
		D2D1::Point2F(267, 177),
		D2D1::Point2F(236, 192),
		D2D1::Point2F(212, 160),
		D2D1::Point2F(156, 255),
		D2D1::Point2F(346, 255),
	};

	pSink->AddLines(points, ARRAYSIZE(points));

	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);
	pSink->Close();
	pSink->Release();

	factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
		hwnd, 
		D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)),
		&target);
	target->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Red),
		&brush);

	target->BeginDraw();

	target->Clear(D2D1::ColorF(D2D1::ColorF::White));
	target->DrawGeometry(geometry, brush, 1.f);
	brush->SetColor(D2D1::ColorF(D2D1::ColorF::OliveDrab, 1.f));
	target->FillGeometry(geometry, brush);
	
	/*target->DrawLine(
		D2D1::Point2F(100.f, 100.f),
		D2D1::Point2F(200.f, 200.f),
		brush);*/

	target->EndDraw();
	
	/*pSink->BeginFigure(
		D2D1::Point2F(346, 255),
		D2D1_FIGURE_BEGIN_FILLED
		);

	D2D1_POINT_2F points[5] = {
		D2D1::Point2F(267, 177),
		D2D1::Point2F(236, 192),
		D2D1::Point2F(212, 160),
		D2D1::Point2F(156, 255),
		D2D1::Point2F(346, 255),
	};

	pSink->AddLines(points, ARRAYSIZE(points));
	pSink->EndFigure(D2D1_FIGURE_END_CLOSED);;

	pSink->Close();
	pSink->Release();*/
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case   WM_PAINT:
		Draw(hwnd);
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
		"Direct2D",					// window caption
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
