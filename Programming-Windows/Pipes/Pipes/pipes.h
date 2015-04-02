#pragma once

#include <Windows.h>

HPALETTE CreateRountine(HWND);
void PaintRountine(HDC, int, int);
void TimerRountine(HDC, HPALETTE);
void DestroyRountine(HWND, HPALETTE);
