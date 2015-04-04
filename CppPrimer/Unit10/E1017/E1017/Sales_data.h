#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(std::string &b) : bookNo(b) {}
	std::string isbn() { return bookNo; }
private:
	std::string bookNo;
};

#endif