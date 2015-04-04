#include <iostream>
#include <string>

#include "Quote.h"

int main()
{
	Quote q("001", 10);
	Bulk_quote bq("002", 10.0, 10, 0.9);

	print_total(std::cout, q, 20);
	print_total(std::cout, bq, 30);

	return 0;
}