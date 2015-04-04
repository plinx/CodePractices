#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data {
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, Sales_data&);
public:
	std::string isbn() const { return id; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string id;
	unsigned sold;
	double revenue;
};

std::istream &read(std::istream &i, Sales_data &data);
std::ostream &print(std::ostream &o, Sales_data &data);

#endif