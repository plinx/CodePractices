#include <iostream>

void fact(int x);

int main()
{
	int x;
	std::cin >> x;
	fact(x);

	return 0;
}

void fact(int x)
{
	std::cout << x << std::endl;
}