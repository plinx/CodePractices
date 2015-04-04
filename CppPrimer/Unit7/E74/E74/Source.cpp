#include <iostream>
#include "Person.h"

int main()
{
	Person man;
	std::cout << "Enter man informations:" << std::endl;
	std::cin >> man.Name >> man.Addr >> man.number;
	std::cout << "Return man informations:" << std::endl;
	std::cout << man.getName() << " "<< man.getAddr() << " " << man.getNum() << std::endl;

	return 0;
}