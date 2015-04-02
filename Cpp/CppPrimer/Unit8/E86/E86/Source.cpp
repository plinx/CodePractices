#include <iostream>
#include <fstream>
#include "Sales_data.h"

int main(int argc, char *argv[])
{
	Sales_data total;
	if (!argv[1])
	{
		std::cout << "No input file." << std::endl;
		return -1;
	}
	std::ifstream in(argv[1]);
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data" << std::endl;
	}
	return 0;
}