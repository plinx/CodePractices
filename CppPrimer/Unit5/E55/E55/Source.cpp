#include <iostream>

int main()
{
	int grade;

	while (std::cin >> grade) {
		if (grade > 90) {
			std::cout << 'A' << std::endl;
		} else if (grade > 75) {
			std::cout << 'B' << std::endl;
		} else if (grade > 60) {
			std::cout << 'C' << std::endl;
		} else
			std::cout << 'D' << std::endl;
	}

	return 0;
}