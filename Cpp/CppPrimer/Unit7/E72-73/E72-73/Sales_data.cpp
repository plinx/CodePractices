#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	sold += rhs.sold;
	revenue += rhs.revenue;
	return *this;
}