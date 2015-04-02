#ifndef system_h
#define system_h

#include <Windows.h>

#define NUMLINES ((int) (sizeof(sysmetrics) / sizeof(sysmetrics[0])))

struct 
{
	int Index;
	TCHAR *Lable;
	TCHAR *Desc;
}
sysmetrics[] =
{
	SM_CXSCREEN, TEXT("SM_CXSCREEN"), TEXT("Screen width in pixel"),
	SM_CYSCREEN, TEXT("SM_CYSCREEN"), TEXT("Screen height in pixel"),
	SM_CXBORDER, TEXT("SM_CXBORDER"), TEXT("Window border width"),
	SM_CYBORDER, TEXT("SM_CYBORDER"), TEXT("Window border height")
};

#endif