#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data data1;
	Sales_data data2("test");
	Sales_data data3(std::cin);
	Sales_data data4("111", 1, 1);

	std::cout << "Enter data1 : " << std::endl;
	read(std::cin, data1);
	print(std::cout, data1);

	print(std::cout, data2);

	print(std::cout, data3);

	print(std::cout, data4);

	return 0;
}