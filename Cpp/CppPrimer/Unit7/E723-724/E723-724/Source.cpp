#include <iostream>
#include "Screen.h"

int main()
{
	Screen s1(80, 24, 'x');
	Screen s2 = s1;
	s1.move(25, 25);
	std::cout << s1.get(0, 0) << std::endl;
	std::cout << s2.get(2, 2) << std::endl;

	return 0;
}