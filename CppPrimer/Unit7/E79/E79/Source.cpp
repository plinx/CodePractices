#include <iostream>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Person person;
	std::cout << "Enter name and address :";
	read(cin, person);
	print(cout, person);

	return 0;
}