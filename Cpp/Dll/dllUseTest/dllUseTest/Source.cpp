#include <iostream>
#include "dllTest.h"

int main()
{
	std::cout << add1(1, 2) << std::endl;
	std::cout << test::add2(1, 3) << std::endl;
	test::DllTest dllTest;
	std::cout << dllTest.add3(1, 4) << std::endl;

	system("pause");
	return 0;
}