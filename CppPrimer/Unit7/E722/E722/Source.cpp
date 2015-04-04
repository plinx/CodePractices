#include <iostream>
#include "Person.h"

int main()
{
	Person p1;
	Person p2("p2");
	Person p3("p3", "addr3");

	read(std::cin, p1);
	std::cout << "Person 1:" << std::endl;
	print(std::cout, p1);
	std::cout << "Person 2:" << std::endl;
	print(std::cout, p2);
	std::cout << "Person 3:" << std::endl;
	print(std::cout, p3);
	return 0;
}