#include <iostream>

int func();

int main()
{
	std::cout << func() << std::endl;
	std::cout << func() << std::endl;
	std::cout << func() << std::endl;

	return 0;
}

int func()
{
	static int i = 0;

	return i++;
}