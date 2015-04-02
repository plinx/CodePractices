#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	do {
		string str1, str2;
		cout << "Enter str 1 : ";
		cin >> str1;
		cout << "Enter str 2 : ";
		cin >> str2;

		cout << ((str1.size() < str2.size()) ? str1 : str2) << endl;
	} while (cin);

	return 0;
}