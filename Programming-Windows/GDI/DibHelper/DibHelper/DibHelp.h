#include <Windows.h>

typedef void* HDIB;

typedef struct
{
	PBYTE *ppRow;
	int iSignature;
	HBITMAP hBitmap;
	BYTE *pBits;
	DIBSECTION ds;
	int iRShift[3];
	int iLShift[3];
}DIBSTRUCT, *PDIBSTRUCT;

BOOL DibIsValid(HDIB hdib);
HBITMAP DibBitMapHandle(HDIB hdib);
int DibWidth(HDIB hdib);
int DibHeight(HDIB hdib);
int DibBitCount(HDIB hdib);
int DibRowLength(HDIB hdib);
int DibNumColors(HDIB hdib);
DWORD DibMask(HDIB hdib, int i);
int DibRShift(HDIB hdib, int i);
int DibLShift(HDIB hdib, int i);
int DibCompression(HDIB hdib);
BOOL DibIsAddressable(HDIB hdib);
DWORD DibInfoHeaderSize(HDIB hdib);
DWORD DibMaskSize(HDIB hdib);
DWORD DibColorSize(HDIB hdib);
DWORD DibInfoSize(HDIB hdib);
DWORD DibBitsSize(HDIB hdib);
DWORD DibTotalSize(HDIB hdib);
BITMAPINFOHEADER *DibInfoHeaderPtr(HDIB hdib);
DWORD *DibMaskPtr(HDIB hdib);
void *DibBitsPtr(HDIB hdib);
BOOL DibGetColor(HDIB hdib, int index, RGBQUAD *prgb);
BOOL DibSetColor(HDIB hdib, int index, RGBQUAD *prgb);
BYTE *DibPixelPtr(HDIB hdib, int x, int y);
DWORD DibGetPixel(HDIB hdib, int x, int y);
BOOL DibSetPixel(HDIB hdib, int x, int y, DWORD dwPixel);
BOOL DibGetPixelColor(HDIB hdib, int x, int y, RGBQUAD *prgb);
BOOL DibSetPixelColor(HDIB hdib, int x, int y, RGBQUAD *prgb);
HDIB DibCreateFromInfoHeader(BITMAPINFO *pbmi);
BOOL DibDelete(HDIB hdib);
HDIB DibCreate(int cx, int xy, int cBits);
HDIB DibFileLoad(HDIB hdib, HWND hwnd, HPALETTE hPalette);
HDIB DibFileSave(HDIB hdib, const TCHAR * szFileName);
HBITMAP DibCopyToDdb(HDIB hDib, HWND hwnd, HPALETTE hPalette);
HDIB DibCreateFromDdb(HBITMAP hBitmap);


// Quickie no-bounds-checked pixel gets and sets

#define DibPixelPtr1(hdib, x, y) (((* (PBYTE **)hdib)[y]) + ((x) >> 3))
#define DibPixelPtr4(hdib, x, y) (((* (PBYTE **)hdib)[y]) + ((x) >> 1))
#define DibPixelPtr8(hdib, x, y) (((* (PBYTE **)hdib)[y]) + (x))
#define DibPixelPtr16(hdib, x, y) (((* (PBYTE **)hdib)[y]) + ((x) * 2))
#define DibPixelPtr24(hdib, x, y) (((* (PBYTE **)hdib)[y]) + ((x) * 3))
#define DibPixelPtr32(hdib, x, y) (((* (PBYTE **)hdib)[y]) + ((x) * 4))

#define DibGetPixel1(hdib, x, y) (0x01 & (* DibPixelPtr1(hdib, x, y) >> (7 - ((x) & 7))))
#define DibGetPixel4(hdib, x, y) (0x0F & (* DibPixelPtr4(hdib, x, y) >> ((x) & 1 ? 0 : 4)))
#define DibGetPixel8(hdib, x, y) (* DibPixelPtr8(hdib, x, y))
#define DibGetPixel16(hdib, x, y) (* DibPixelPtr16(hdib, x, y))
#define DibGetPixel24(hdib, x, y) (* DibPixelPtr24(hdib, x, y))
#define DibGetPixel32(hdib, x, y) (* DibPixelPtr32(hdib, x, y))

#define DibSetPixel1(hdib, x, y, p) ((* DibPixelPtr1(hdib, x, y) &= ~(1 << (7 - ((x) & 7)))), (* DibPixelPtr1(hdib, x, y) |= ((p) << (7 - ((x) & 7)))))
#define DibSetPixel4(hdib, x, y, p) ((* DibPixelPtr4(hdib, x, y) &= ~(0x0F << (((x) & 1 ? 4 : 0))), (* DibPixelPtr1(hdib, x, y) |= ((p) << ((x) & 1 ? 0 : 4))))
#define DibSetPixel8(hdib, x, y, p) (* DibPixelPtr8(hdib, x, y) = p)
#define DibSetPixel16(hdib, x, y, p) (* DibPixelPtr16(hdib, x, y) = p)
#define DibSetPixel24(hdib, x, y, p) (* DibPixelPtr24(hdib, x, y) = p)
#define DibSetPixel32(hdib, x, y, p) (* DibPixelPtr32(hdib, x, y) = p)

