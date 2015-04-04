#include "Sales_data.h"

Sales_data::Sales_data(std::istream &i)
{
	read(i, *this);
}

Sales_data &Sales_data::combine(const Sales_data &data)
{
	sold += data.sold;
	revenue += data.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if (sold)
		return revenue / sold;
	else
		return 0;
}

Sales_data add(Sales_data &data1, Sales_data &data2)
{
	Sales_data sum = data1;
	sum.combine(data2);
	return sum;
}

std::istream &read(std::istream &i, Sales_data &data)
{
	double price;
	i >> data.bookID >> data.sold >> price;
	data.revenue = price * data.sold;
	return i;
}

std::ostream &print(std::ostream &o, Sales_data &data)
{
	o << data.bookID << " " << data.sold << " "
		<< data.avg_price() << " " << data.revenue << std::endl;
	return o;
}