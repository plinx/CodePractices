#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <string>
using std::string;

struct Sales_data {
	Sales_data() = default;
	Sales_data(std::istream&);
	Sales_data(const string &id, const int &s, const double &r) :
		bookID(id), sold(s), revenue(r) { }

	string bookid() const { return bookID; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	string bookID;
	int sold;
	double revenue;
};

Sales_data add(Sales_data&, Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, Sales_data&);

#endif