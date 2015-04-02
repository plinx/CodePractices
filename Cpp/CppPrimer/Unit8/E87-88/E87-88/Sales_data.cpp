#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &data)
{
	sold += data.sold;
	revenue += data.revenue;

	return *this;
}

double Sales_data::avg_price() const
{
	return revenue / sold;
}

std::istream &read(std::istream &i, Sales_data &data)
{
	double price;
	i >> data.id >> data.sold >> price;
	data.revenue = price * data.sold;
	return i;
}

std::ostream &print(std::ostream &o, Sales_data &data)
{
	o << data.isbn() << " " << data.sold << " "
		<< data.revenue << " " << data.avg_price();
	return o;
}