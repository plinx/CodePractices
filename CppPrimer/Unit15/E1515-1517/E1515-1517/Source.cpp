#include <iostream>
#include <string>

#include "Header.h"

int main()
{
	//Disc_quote dq;
	//Disc_qoute cannot instantiate abstract class due to folowing menbers:
	//double Disc_quote::net_price(size_t) const is abstract
	book_quote bq("001", 20, 5, 0.9, 10);

	bq.get_price();

	return 0;
}