#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string upstr{ "bdfhklt" };
	string dowmstr{ "gjpqy" };
	string str;

	cin >> str;
	string::size_type pos = 0;
	while (((pos = str.find_first_not_of(upstr, pos)) != string::npos) &&
		((pos = str.find_first_not_of(dowmstr, pos)) != string::npos))
	{
		cout << str[pos];
		++pos;
	}
	cout << endl;

	return 0;
}