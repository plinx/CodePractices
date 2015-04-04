#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str, total1, total2;
	cout << "Enter string:" << endl;
	if (cin >> str) {
		total1 = str;
		total2 = str;
	}
	while (cin >> str) {
		total1 += str;
		total2 += " " + str;
	}

	cout << "total string without blank :" << endl;
	cout << total1 << endl;
	cout << "total string with blank :" << endl;
	cout << total2 << endl;

	return 0;
}