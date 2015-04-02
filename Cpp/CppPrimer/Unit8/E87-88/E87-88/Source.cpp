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
	if (!argv[2])
	{
		std::cout << "No output file." << std::endl;
		return -1;
	}
	std::ifstream in(argv[1]);
	std::ofstream out(argv[2], std::ofstream::app);
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
				print(out, total) << std::endl;
				total = trans;
			}
		}
		print(out, total) << std::endl;
	}
	else
	{
		std::cerr << "No data" << std::endl;
	}
	return 0;
}