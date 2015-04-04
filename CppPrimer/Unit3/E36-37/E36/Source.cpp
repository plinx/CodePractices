#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string tstr1("test string 1");
	string tstr2("test string 2");
	for (auto &s : tstr1) {
		s = 'X';
	}
	for (char &c : tstr2) {
		c = 'X';
	}
	cout << "tstr1 :" << tstr1 << endl;
	cout << "tstr2 :" << tstr2 << endl;

	return 0;
}