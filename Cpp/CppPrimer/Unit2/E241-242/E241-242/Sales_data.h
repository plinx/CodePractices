#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data {
	std::string BookId;
	std::string BookName;
	float TotalPrice;
	float SoldNum;
	float AvgPrice;
};

#endif