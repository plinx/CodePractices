#pragma once

#include <Windows.h>

HPALETTE CreateRountine(HWND hwnd);
void PaintRountine(HDC hdc, int cxClient, int cyClient);
void TimerRountine(HDC hdc, HPALETTE hPalette);
void DestroyRountine(HWND hwnd, HPALETTE hPalette);