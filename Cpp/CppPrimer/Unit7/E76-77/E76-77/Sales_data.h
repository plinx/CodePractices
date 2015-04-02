#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
	std::string isbn() const { return bookID; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string bookID;
	unsigned sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif