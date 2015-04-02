#include <iostream>

int func(int x);

int main()
{
	int x; 
	std::cin >> x;
	std::cout << func(x) << std::endl;

	return 0;
}

int func(int x)
{
	return abs(x);
}