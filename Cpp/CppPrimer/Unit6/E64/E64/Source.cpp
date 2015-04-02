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
	int ret = 1, ix = 1;
	if (x <= 0) return 0;
	while (ix < x) {
		++ix;
		ret *= ix;
	}

	return ret;
}