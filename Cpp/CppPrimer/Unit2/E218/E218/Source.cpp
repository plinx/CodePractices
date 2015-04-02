#include <iostream>

int main()
{
	int i = 1, ni = 2;
	int *pi;

	pi = &i;
	std::cout << *pi << std::endl;
	pi = &ni;
	ni++;
	std::cout << *pi << std::endl;

	return 0;
}