#include <iostream>
#include <exception>

int main()
{
	int val1, val2;

	std::cin >> val1 >> val2;
	if (val2 == 0) throw std::runtime_error("val2 is 0");
	std::cout << val1 / val2 << std::endl;

	return 0;
}