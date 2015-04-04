#include <iostream>
#include <vector>
#include <algorithm>

#include "Sales_data.h"

bool compareIsbn(const Sales_data&, const Sales_data&);
bool compareIsbnLen(const Sales_data&, const Sales_data&);

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
	sort(data.begin(), data.end(), compareIsbn);
	sort(data.begin(), data.end(), compareIsbnLen);
	//stable_sort(data.begin(), data.end(), compareIsbnLen);	// same result

	for (auto &d : data)
	{
		std::cout << d.isbn() << " ";
	}
	std::cout << std::endl;

	return 0;
}

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}

bool compareIsbnLen(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn().size() < sd2.isbn().size();
}
