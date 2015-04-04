#include <iostream>
#include "Person.h"

int main()
{
	Person p1;
	Person p2(std::cin);
	Person p3("person3");
	Person p4("person4", "addr4");

	std::cout << "Enter person1 informations : " << std::endl;
	read(std::cin, p1);
	print(std::cout, p1);

	print(std::cout, p2);
	
	print(std::cout, p3);

	print(std::cout, p4);

	return 0;
}