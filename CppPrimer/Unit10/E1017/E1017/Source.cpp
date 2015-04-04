#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.h"

int main()
{
	std::vector<Sales_data> data;
	Sales_data d1{ std::string("007") };
	Sales_data d2{ std::string("003") };
	Sales_data d3{ std::string("00012") };
	Sales_data d4{ std::string("00112") };
	data.push_back(d1);
	data.push_back(d2);
	data.push_back(d3);
	data.push_back(d4);
	sort(data.begin(), data.end(), 
		[](Sales_data &sd1, Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); });
	sort(data.begin(), data.end(), 
		[](Sales_data &sd1, Sales_data &sd2) { return sd1.isbn().size() < sd2.isbn().size(); });

	for (auto &d : data)
	{
		std::cout << d.isbn() << " ";
	}
	std::cout << std::endl; 

	return 0;
}