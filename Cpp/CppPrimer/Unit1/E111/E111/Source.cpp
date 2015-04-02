#include <iostream>

int main()
{
	int val1, val2;
	std::cout << "Enter two element : ";
	std::cin >> val1 >> val2;
	if (val1 > val2) {
		val1 = val1^val2;
		val2 = val1^val2;
		val1 = val1^val2;
	}
	while (val1 <= val2) {
		std::cout << val1 << std::endl;
		val1++;
	}

	return 0;
}