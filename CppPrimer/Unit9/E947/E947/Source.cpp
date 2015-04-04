#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

int main()
{
	
	string str{ "ab2c3d7R4E6" };
	string numbers{ "0123456789" };

	string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "Found number " << str[pos] << " at index : " << pos << endl;
		++pos;
	}
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << "Found " << str[pos] << " at index : " << pos << endl;
		++pos;
	}


	return 0;
}