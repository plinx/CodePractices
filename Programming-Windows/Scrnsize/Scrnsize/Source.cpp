#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

int CDECL MessageBoxPrint(TCHAR *szCaption, TCHAR *szFormat, ...)
{
	TCHAR szBuf[1024];
	va_list pArgList;

	va_start(pArgList, szFormat);
	_vsnprintf_s(szBuf, sizeof(szBuf) / sizeof(TCHAR), szFormat, pArgList);
	va_end(pArgList);

	return MessageBox(NULL, szBuf, szCaption, 0);
}

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	int cxScreen, cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrint(
		TEXT("ScrnSize"),
		TEXT("The Screen is %i pixels wide by %i pixels high."),
		cxScreen, cyScreen);

	return 0;
}