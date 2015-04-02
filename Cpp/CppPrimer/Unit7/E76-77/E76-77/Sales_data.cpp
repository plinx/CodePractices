#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &data)
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

Sales_data add(const Sales_data &sd1, const Sales_data &sd2)
{
	Sales_data sum = sd1;
	sum.combine(sd2);
	return sum;
}

std::ostream &print(std::ostream &o, const Sales_data &data)
{
	o << data.isbn() << " " << data.sold << " "
		<< data.revenue << " " << data.avg_price() << std::endl;

	return o;
}
std::istream &read(std::istream &i, Sales_data &data)
{
	double price = 0;
	i >> data.bookID >> data.sold >> price;
	data.revenue = price * data.sold;
	return i;
}