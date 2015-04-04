#include <iostream>
#include <string>

#include "Quote.h"

int main()
{
	book_quote bq("001", 20, 5, 0.9, 10);

	bq.get_price();

	return 0;
}