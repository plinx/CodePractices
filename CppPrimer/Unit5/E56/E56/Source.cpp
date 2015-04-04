#include <iostream>
#include <string>

int main()
{
	int grade;
	std::string sg;

	while (std::cin >> grade) {
		sg = (grade > 90) ? "A"
			: (grade > 75) ? "B"
			: (grade > 60) ? "C" : "D";
		std::cout << sg << std::endl;
	}

	return 0;
}