#pragma once


#ifdef DLLTEST_API 
#define DLLTEST_API __declspec(dllimport)
#else 
#define DLLTEST_API __declspec(dllexport)
#endif

DLLTEST_API int add1(int a, int b);

namespace test
{
	DLLTEST_API int add2(int a, int b);

	class DLLTEST_API DllTest
	{
	public:
		DllTest();
		int add3(int a, int b);
	};
}