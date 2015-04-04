#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data total;
	if (cin >> total.bookID)
	{
		Sales_data trans;
		while (cin >> trans.bookID)
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout << total.bookID << endl;
				total = trans;
			}
		}
	}

	return 0;
}