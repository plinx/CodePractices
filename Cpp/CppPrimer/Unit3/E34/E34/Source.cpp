#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1, str2;

	cout << "Enter string 1 : ";
	cin >> str1;
	cout << "Enter string 2 : ";
	cin >> str2;

	if (str1 == str2) {
		cout << "string 1 equals string 2" << endl;
	} else if (str1 > str2) {
		cout << "string 1 larger than string 2" << endl;
	} else {
		cout << "string 2 larger than string 1" << endl;
	}

	if (str1.size() == str2.size()) {
		cout << "string 1 equals string 2" << endl;
	} else if (str1.size() > str2.size()) {
		cout << "string 1 longer than string 2" << endl;
	} else {
		cout << "string 2 longer than string 1" << endl;
	}

	return 0;
}