#include <iostream>
#include <vector>
#include "Header.h"

int main()
{
	C c1(1);
	C c2;
	std::vector<NoDefault> v1(10);
	std::vector<NoDefault> v2{ 10 };
	NoDefault nd(1);
	c1.print();
	c2.print();

	v1.push_back(nd);

	std::cout << "v1 :" << v1[0].rval() << std::endl;
	std::cout << "v2 :" << v2[0].rval() << std::endl;

	return 0;
}