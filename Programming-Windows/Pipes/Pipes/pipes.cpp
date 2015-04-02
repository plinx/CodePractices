#include "pipes.h"

#define ID_TIMER 1

static LOGPALETTE *plp;

HPALETTE CreateRountine(HWND hwnd)
{
	HPALETTE hPalette;
	int i;

	plp = (LOGPALETTE *)malloc(sizeof(LOGPALETTE) + 32 * sizeof(PALETTEENTRY));
	plp->palVersion = 0x300;
	plp->palNumEntries = 16;

	for (i = 0; i <= 8; i++)
	{
		plp->palPalEntry[i].peRed = (BYTE)min(255, 0x20 * i);
		plp->palPalEntry[i].peGreen = 0;
		plp->palPalEntry[i].peBlue = (BYTE)min(255, 0x20 * i);
		plp->palPalEntry[i].peFlags = PC_RESERVED;
		plp->palPalEntry[16 - i] = plp->palPalEntry[i];
		plp->palPalEntry[16 + i] = plp->palPalEntry[i];
		plp->palPalEntry[32 - i] = plp->palPalEntry[i];
	}

	hPalette = CreatePalette(plp);
	SetTimer(hwnd, ID_TIMER, 100, NULL);
	return hPalette;
}

void PaintRountine(HDC hdc, int cxClient, int cyClient)
{
	HBRUSH hBrush;
	int i;
	RECT rect;

	SetRect(&rect, 0, 0, cxClient, cyClient);
	hBrush = (HBRUSH)SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	FillRect(hdc, &rect, hBrush);

	for (i = 0; i < 128; i++)
	{
		hBrush = CreateSolidBrush(PALETTEINDEX(i % 16));
		SelectObject(hdc, hBrush);

		rect.left = (127 - i) * cxClient / 128;
		rect.right = (128 - i) * cxClient / 128;
		rect.top = 4 * cyClient / 14;
		rect.bottom = 5 * cyClient / 14;
		FillRect(hdc, &rect, hBrush);
		
		rect.left = i * cxClient / 128;
		rect.right = (i + 1) * cxClient / 128;
		rect.top = 9 * cyClient / 14;
		rect.bottom = 10 * cyClient / 14;
		FillRect(hdc, &rect, hBrush);

		DeleteObject(SelectObject(hdc, GetStockObject(WHITE_BRUSH)));
	}

	MoveToEx(hdc, 0, 4 * cyClient / 14, NULL);
	LineTo(hdc, cxClient, 4 * cyClient / 14);
	
	MoveToEx(hdc, 0, 5 * cyClient / 14, NULL);
	LineTo(hdc, cxClient, 5 * cyClient / 14);
	
	MoveToEx(hdc, 0, 9 * cyClient / 14, NULL);
	LineTo(hdc, cxClient, 9 * cyClient / 14);

	MoveToEx(hdc, 0, 10 * cyClient / 14, NULL);
	LineTo(hdc, cxClient, 10 * cyClient / 14);
}

void TimerRountine(HDC hdc, HPALETTE hPalette)
{
	static int Index;
	AnimatePalette(hPalette, 0, 16, plp->palPalEntry + Index);
	Index = (Index + 1) % 16;
}

void DestroyRountine(HWND hwnd, HPALETTE hPalette)
{
	KillTimer(hwnd, ID_TIMER);
	DeleteObject(hPalette);
	free(plp);
}

