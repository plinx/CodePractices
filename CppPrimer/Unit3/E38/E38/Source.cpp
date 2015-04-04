#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1 = "test string 1";
	string str2 = "test string 2";

	for (auto &s : str1) {
		s = 'X';
	}

	int i = 0;
	while (i < str2.size()) {
		str2[i++] = 'X';
	}

	cout << "str1 :" << str1 << endl;
	cout << "str2 :" << str2 << endl;

	return 0;
}