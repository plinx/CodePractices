#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data data1, data2;
	std::cin >> data1.sold >> data2.sold;
	std::cin >> data1.revenue >> data2.revenue;

	if (data1.bookID == data2.bookID)
	{
		std::cout << data1.sold + data2.sold << std::endl;
		std::cout << data1.revenue + data2.revenue << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN"
			<< std::endl;
		return -1;
	}
	return 0;
	
}