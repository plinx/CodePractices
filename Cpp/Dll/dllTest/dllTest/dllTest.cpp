// dllTest.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "dllTest.h"

int add1(int a, int b)
{
	return a + b;
}

int test::add2(int a, int b)
{
	return a + b;
}

test::DllTest::DllTest()
{
}

int test::DllTest::add3(int a, int b)
{
	return a + b;
}


