#include <iostream>

int main()
{
	int x[10];
	int *p;
	std::cout << sizeof(x) / sizeof(*x) << std::endl;
	std::cout << sizeof(p) / sizeof(*p) << std::endl;

	return 0;
}