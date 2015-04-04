#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <string>

struct Sales_data {
	std::string bookID;
	unsigned sold = 0;
	double revenue = 0.0;
};

#endif