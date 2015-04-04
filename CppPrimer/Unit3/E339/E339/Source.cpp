#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str1 = "string 1";
	string str2 = "string 2";
	char ch1[] = "char string 1";
	char ch2[] = "char string 2";

	if (str1 < str2) {
		cout << "string 1 < string 2" << endl;
	} else if (str1 > str2) {
		cout << "string 1 > string 2" << endl;
	} else {
		cout << "string 1 == string 2" << endl;
	}

	if (strcmp(ch1, ch2) < 0) {
		cout << "char string 1 < char string 2" << endl;
	} else if (strcmp(ch1, ch2) > 0) {
		cout << "char string 1 > char string 2" << endl;
	} else {
		cout << "char string 1 == char string 2" << endl;
	}

	return 0;
}