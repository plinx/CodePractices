#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
using std::string;

struct Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, Sales_data&);
public:
	//Sales_data() = default;
	//Sales_data(std::istream&);
	Sales_data(const string &id, const int &s, const double &r) :
		bookID(id), sold(s), revenue(r) 
	{ 
		std::cout << "Sales_data(const string &id, const int &s, const double &r)" << std::endl;
	}

	Sales_data() : Sales_data("", 0, 0) 
	{
		std::cout << "Sales_data()" << std::endl;
	}
	Sales_data(string s) : Sales_data(s, 0, 0) 
	{
		std::cout << "Sales_data(string s)" << std::endl;
	}
	Sales_data(std::istream &i) :Sales_data() 
	{ 
		read(i, *this); 
		std::cout << "Sales_data(std::istream &i)" << std::endl;
	}

	string bookid() const { return bookID; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

private:
	string bookID;
	int sold;
	double revenue;
};

Sales_data add(Sales_data&, Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, Sales_data&);

#endif