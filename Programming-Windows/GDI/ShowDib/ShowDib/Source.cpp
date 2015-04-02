#include <Windows.h>
#include "resource.h"
#include "dibfile.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("ShowDib");
	HACCEL hAccel;
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szAppName;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Fail to register class."),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName, TEXT("DibWindow"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	hAccel = LoadAccelerators(hInstance, szAppName);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(hwnd, hAccel, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static BITMAPFILEHEADER *pbmfh;
	static BITMAPINFO *pbmi;
	static BYTE *pBits;
	static int cxClient, cyClient, cxSrc, cySrc;
	static TCHAR szFileName[1024], szTitleName[1024];
	BOOL bSuccess;

	HDC hdc;
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_CREATE:
		DibFileInitialize(hwnd);
		return 0;
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;
	case WM_INITMENUPOPUP:
		EnableMenuItem((HMENU)wParam, ID_FILE_SAVE,
			pbmfh ? MF_ENABLED : MF_GRAYED);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILE_OPEN:
			if (!DibFileOpenDlg(hwnd, szFileName, szTitleName))
				return 0;
			if (pbmfh)
			{
				free(pbmfh);
				pbmfh = NULL;
			}

			SetCursor(LoadCursor(NULL, IDC_WAIT));
			ShowCursor(TRUE);

			pbmfh = DibLoadImage(szFileName);
			ShowCursor(FALSE);
			SetCursor(LoadCursor(NULL, IDC_ARROW));

			InvalidateRect(hwnd, NULL, TRUE);

			if (pbmfh == NULL)
			{
				MessageBox(hwnd, TEXT("Cannot load DIB file"),
					szFileName, 0);
				return 0;
			}

			pbmi = (BITMAPINFO *)(pbmfh + 1);
			pBits = (BYTE *)(pbmfh + pbmfh->bfOffBits);

			if (pbmi->bmiHeader.biSize == sizeof(BITMAPFILEHEADER))
			{
				cxSrc = ((BITMAPCOREHEADER *)pbmi)->bcWidth;
				cySrc = ((BITMAPCOREHEADER *)pbmi)->bcHeight;
			}
			else
			{
				cxSrc = pbmi->bmiHeader.biWidth;
				cySrc = abs(pbmi->bmiHeader.biHeight);
			}
			return 0;
		case ID_FILE_SAVE:
			if (!DibFileSaveDlg(hwnd, szFileName, szTitleName))
				return 0;

			SetCursor(LoadCursor(NULL, IDC_WAIT));
			ShowCursor(TRUE);

			bSuccess = DibSaveImage(szFileName, pbmfh);
			ShowCursor(FALSE);
			SetCursor(LoadCursor(NULL, IDC_ARROW));

			if (!bSuccess)
				MessageBox(hwnd, TEXT("Cannot Save DIB file"),
				szFileName, 0);

			return 0;
		default:
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (pbmfh)
			SetDIBitsToDevice(hdc, 0, 0, cxSrc, cySrc, 0, 0,
				0, cySrc, pBits, pbmi, DIB_RGB_COLORS);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		if (pbmfh)
			free(pbmfh);
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

