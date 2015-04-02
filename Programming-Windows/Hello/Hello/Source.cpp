#include <Windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	MessageBox(NULL, TEXT("Hello, Windows."), TEXT("Hello MsgBox"), 0);

	return 0;
}