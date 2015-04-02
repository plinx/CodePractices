#include <iostream>

int main()
{
	int val1, val2;
	std::cout << "Enter two element :";
	std::cin >> val1 >> val2;
	if (val1 > val2) {
		val1 = val1^val2;
		val2 = val1^val2;
		val1 = val1^val2;
	}
	for (int i = val1; i <= val2; i++) {
		std::cout << i << std::endl;
	}
	return 0;
}