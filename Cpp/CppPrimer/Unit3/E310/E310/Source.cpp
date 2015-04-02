#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str, nstr;
	
	getline(cin, str);

	for (auto s : str) {
		if (s == ',' || s == '.') {
			continue;
		}
		nstr += s;
	}

	cout << "old string :" << str << endl;
	cout << "new string :" << nstr << endl;

	return 0;
}