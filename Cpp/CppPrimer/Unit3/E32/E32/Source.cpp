#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string line, word;

	if (getline(cin, line))
		cout << "Get string :" << line << endl;

	while (cin >> word) {
		cout << "Get word :" << word << endl;
	}


	return 0;
}