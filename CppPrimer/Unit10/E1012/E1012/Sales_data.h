#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(std::string &b) : bookNo(b) {}
	Sales_data(std::string &b, int s) : bookNo(b), sold(s) {}
	std::string isbn() const { return bookNo; }
	double avrage() { return avenue / sold; }
	
private:
	std::string bookNo;
	int sold;
	double avenue;
};

#endif