#include <iostream>
#include <string>

int main()
{
	int grade;
	std::string finalgrade;
	std:: cin >> grade;
	finalgrade = (grade > 90) ? "High pass"
		: (grade > 75) ? "Pass"
		: (grade > 60) ? "Low Pass" : "Fail";

	std::cout << finalgrade;

	return 0;
}