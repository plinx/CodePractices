#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string tmpstr;
	vector<string> str;

	while (cin >> tmpstr) {
		for (auto &s : tmpstr) {
			s = toupper(s);
		}
		str.push_back(tmpstr);
	}

	for (auto s : str) {
		cout << s << endl;
	}

	return 0;

}