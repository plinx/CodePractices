#include <iostream>
#include <string>

#include "Quote.h"

int main()
{
	Quote q("001", 15);
	Bulk_quote bq("002", 20, 10, 0.9);

	q.debug();
	bq.debug();

	return 0;
}