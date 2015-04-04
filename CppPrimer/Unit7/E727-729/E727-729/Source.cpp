#include <iostream>
#include "Screen.h"

int main()
{
	Screen myScreen(5, 5, 'x');
	Screen tmpScreen;
	std::cout << "myScreen" << std::endl;
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;

	std::cout << "tmpScreen" << std::endl;
	tmpScreen = myScreen.move(3, 0);
	tmpScreen.set('#').display(std::cout);
	std::cout << std::endl;
	tmpScreen.display(std::cout);
	std::cout << std::endl;

	std::cout << "myScreen" << std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;

	return 0;
	
}