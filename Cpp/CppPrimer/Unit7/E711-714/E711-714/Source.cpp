#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;

int main()
{
	Sales_data data1;
	Sales_data data2(cin);
	Sales_data data3("defaultID", 5, 500);

	cout << "Enter data1 : " << std::endl;
	read(cin, data1);
	print(cout, data1);

	print(cout, data2);

	print(cout, data3);

	return 0;

}