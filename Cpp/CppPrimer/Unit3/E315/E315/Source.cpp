#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<string> str;
	string tstr;

	while (cin >> tstr) {
		str.push_back(tstr);
	}

	for (auto s : str) {
		cout << s << endl;
	}

	return 0;
}