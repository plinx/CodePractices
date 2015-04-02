#include <iostream>

int retmax(int, int*);

int main()
{
	int i1, i2;
	int *pi = &i2;

	std::cin >> i1 >> i2;
	std::cout << retmax(i1, pi);

	return 0;
}

int retmax(int i, int *pi)
{
	return i > *pi ? i : *pi;
}