#include "DibHelp.h"

#define HDIB_SIGNATURE (* (int *) "Dib ")

BOOL DibIsValid(HDIB hdib)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;
	if (pdib == NULL)
		return FALSE;

	if (IsBadReadPtr(pdib, sizeof(DIBSTRUCT)))
		return FALSE;

	if (pdib->iSignature != HDIB_SIGNATURE)
		return FALSE;

	return TRUE;
}

HBITMAP DibBitMapHandle(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return NULL;

	return ((PDIBSTRUCT)hdib)->hBitmap;
}

int DibWidth(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return 0;

	return ((PDIBSTRUCT)hdib)->ds.dsBm.bmWidth;
}

int DibHeight(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return 0;

	return ((PDIBSTRUCT)hdib)->ds.dsBm.bmHeight;
}

int DibBitCount(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return 0;

	return ((PDIBSTRUCT)hdib)->ds.dsBm.bmBitsPixel;
}

int DibRowLength(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return 0;

	return 4 * ((DibWidth(hdib) * DibBitCount(hdib) + 31) / 32);
}

int DibNumColors(HDIB hdib)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;

	if (!DibIsValid(hdib))
		return 0;

	if (pdib->ds.dsBmih.biClrUsed != 0)
		return pdib->ds.dsBmih.biClrUsed;
	else if (DibBitCount(hdib) <= 8)
		return 1 << DibBitCount(hdib);

	return 0;
}

DWORD DibMask(HDIB hdib, int i)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;

	if (!DibIsValid(hdib) || i < 0 || i > 2)
		return 0;

	return pdib->ds.dsBitfields[i];
}

int DibRShift(HDIB hdib, int i)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;

	if (!DibIsValid(hdib) || i < 0 || i > 2)
		return 0;

	return pdib->iLShift[i];
}

int DibLShift(HDIB hdib, int i)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;

	if (!DibIsValid(hdib) || i < 0 || i > 2)
		return 0;

	return pdib->iRShift[i];
}

int DibCompression(HDIB hdib)
{
	if (!DibIsValid(hdib))
		return 0;

	return ((PDIBSTRUCT)hdib)->ds.dsBmih.biCompression;
}

BOOL DibIsAddressable(HDIB hdib)
{
	int iCompression;

	if (!DibIsValid(hdib))
		return FALSE;

	iCompression = DibCompression(hdib);

	if (iCompression == BI_RGB || iCompression == BI_BITFIELDS)
		return TRUE;

	return FALSE;
}

BOOL DibGetColor(HDIB hdib, int index, RGBQUAD *prgb)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;
	HDC hdcMem;
	int iReturn;

	if (!DibIsValid(hdib))
		return 0;

	hdcMem = CreateCompatibleDC(NULL);
	SelectObject(hdcMem, pdib->hBitmap);
	iReturn = GetDIBColorTable(hdcMem, index, 1, prgb);
	DeleteObject(hdcMem);

	return iReturn ? TRUE : FALSE;
}
BOOL DibSetColor(HDIB hdib, int index, RGBQUAD *prgb)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;
	HDC hdcMem;
	int iReturn;

	if (!DibIsValid(hdib))
		return 0;

	hdcMem = CreateCompatibleDC(NULL);
	SelectObject(hdcMem, pdib->hBitmap);
	iReturn = SetDIBColorTable(hdcMem, index, 1, prgb);
	DeleteDC(hdcMem);

	return iReturn ? TRUE : FALSE;
}

BYTE *DibPixelPtr(HDIB hdib, int x, int y)
{
	if (!DibIsAddressable(hdib))
		return NULL;

	if (x < 0 || x >= DibWidth(hdib) || y < 0 || y >= DibHeight(hdib))
		return NULL;

	return (((PDIBSTRUCT)hdib)->ppRow)[y] + (x * DibBitCount(hdib) >> 3);
}
DWORD DibGetPixel(HDIB hdib, int x, int y)
{
	PBYTE pPixel;

	if (!(pPixel = DibPixelPtr(hdib, x, y)))
		return 0;

	switch (DibBitCount(hdib))
	{
	case 1: return 0x01 & (*pPixel >> (7 - (x & 7)));
	case 4: return 0x0F & (*pPixel >> (x & 1 ? 0 : 4));
	case 8: return *pPixel;
	case 16: return *(WORD *)pPixel;
	case 24: return 0x00FFFFFF & *(DWORD *)pPixel;
	case 32: return *(DWORD *)pPixel;
	}
	return 0;
}
BOOL DibSetPixel(HDIB hdib, int x, int y, DWORD dwPixel)
{
	PBYTE pPixel;
	if (!(pPixel = DibPixelPtr(hdib, x, y)))
		return FALSE;

	switch (DibBitCount(hdib))
	{
	case 1: 
		*pPixel &= ~(1 << (7 - (x & 7)));
		*pPixel |= dwPixel << (7 - (x & 7));
		break;
	case 4:
		*pPixel &= 0x0F << (x & 1 ? 4 : 0);
		*pPixel |= dwPixel << (x & 1 ? 0 : 4);
		break;
	case 8:
		*pPixel = (BYTE)dwPixel;
		break;
	case 16:
		*(WORD *)pPixel = (WORD)dwPixel;
		break;
	case 24:
		*(RGBTRIPLE *)pPixel = *(RGBTRIPLE *)dwPixel;
		break;
	case 32:
		*(DWORD *)pPixel = dwPixel;
		break;
	default:
		return FALSE;
	}
	return TRUE;
}
//BOOL DibGetPixelColor(HDIB hdib, int x, int y, RGBQUAD *prgb);
BOOL DibSetPixelColor(HDIB hdib, int x, int y, RGBQUAD *prgb)
{
	DWORD dwPixel;
	int iBitCount;
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;

	iBitCount = DibBitCount(hdib);
	if (iBitCount <= 8)
		return FALSE;
	else if (iBitCount == 24)
	{
		*(RGBTRIPLE *)&dwPixel = *(RGBTRIPLE *)prgb;
		dwPixel &= 0x00FFFFFF;
	}
	else if (iBitCount == 32 && pdib->ds.dsBmih.biCompression == BI_RGB)
	{
		*(RGBQUAD *)&dwPixel = *prgb;
	}
	else
	{
		dwPixel = (((DWORD)prgb->rgbRed >> pdib->iLShift[0]) << pdib->iRShift[0]);
		dwPixel |= (((DWORD)prgb->rgbGreen >> pdib->iLShift[1]) << pdib->iRShift[1]);
		dwPixel |= (((DWORD)prgb->rgbBlue >> pdib->iLShift[2]) << pdib->iRShift[2]);
	}

	DibSetPixel(hdib, x, y, dwPixel);
	return TRUE;
}

HDIB DibCreateFromInfoHeader(BITMAPINFOHEADER *pbmih)
{
	BYTE *pBits;
	PDIBSTRUCT pdib;
	HBITMAP hBitmap;
	int iRowLength, cy, y;

	hBitmap = CreateDIBSection(NULL, (BITMAPINFO *)&pbmih, 0, (void**)&pBits, NULL, 0);
	if (hBitmap == NULL)
		return NULL;

	if (NULL == (pdib = (PDIBSTRUCT)malloc(sizeof(DIBSTRUCT))))
	{
		DeleteObject(hBitmap);
		return NULL;
	}

	pdib->iSignature = HDIB_SIGNATURE;
	pdib->hBitmap = hBitmap;
	pdib->pBits = pBits;

	GetObject(hBitmap, sizeof(DIBSECTION), &pdib->ds);

	pdib->ds.dsBitfields[0] = 0x00FF0000;
	pdib->ds.dsBitfields[1] = 0x0000FF00;
	pdib->ds.dsBitfields[2] = 0x000000FF;

	pdib->iRShift[0] = 16;
	pdib->iRShift[1] = 8;
	pdib->iRShift[2] = 0;

	pdib->iLShift[0] = 0;
	pdib->iLShift[1] = 0;
	pdib->iLShift[2] = 0;

	cy = DibHeight(pdib);
	if (NULL == (pdib->ppRow = (PBYTE *)malloc(cy * sizeof(BYTE *))))
	{
		free(pdib);
		DeleteObject(hBitmap);
		return NULL;
	}

	iRowLength = DibRowLength(pdib);
	if (pbmih->biHeight > 0)
	{
		for (y = 0; y < cy; y++)
		{
			pdib->ppRow[y] = pBits + (cy - y - 1) * iRowLength;
		}
	}
	else
	{ 
		for (y = 0; y < cy; y++)
		{
			pdib->ppRow[y] = pBits + y * iRowLength;
		}
	}

	return pdib;
}

BOOL DibDelete(HDIB hdib)
{
	PDIBSTRUCT pdib = (PDIBSTRUCT)hdib;
	if (!DibIsValid(hdib))
		return FALSE;

	free(pdib->ppRow);
	DeleteObject(pdib->hBitmap);
	free(pdib);
	return TRUE;
}

HDIB DibCreate(int cx, int cy, int cBits)
{
	BITMAPINFOHEADER *pbmih = (BITMAPINFOHEADER *)malloc(sizeof(BITMAPINFOHEADER));
	HDIB hdib;

	pbmih->biSize = sizeof(BITMAPINFOHEADER);
	pbmih->biWidth = cx;
	pbmih->biHeight = cy;
	pbmih->biPlanes = 1;
	pbmih->biBitCount = cBits;
	pbmih->biCompression = BI_RGB;
	pbmih->biSizeImage = 0;
	pbmih->biXPelsPerMeter = 0;
	pbmih->biYPelsPerMeter = 0;
	pbmih->biClrUsed = 0;
	pbmih->biClrImportant = 0;

	hdib = DibCreateFromInfoHeader(pbmih);
	free(pbmih);

	return hdib;
}
