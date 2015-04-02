#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str, tmp;
	int dflag = 1;
	while (cin >> str) {
		if (tmp == str) {
			cout << "str " << str << " appear twice." << endl;
			dflag = 0;
		}
		if (str[0] == toupper(str[0]))
			tmp = str;
	}
	if (dflag) cout << "no str appear twice." << endl;

	return 0;
}