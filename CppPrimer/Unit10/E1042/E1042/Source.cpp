#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void elimDups(list<string>&);

int main()
{
	list<string> lstr = {
		"2asf", "asdf", "asdf", "qqqww", "qqqwq", "qqqwq"
	};
	elimDups(lstr);

	for (auto &l : lstr)
	{
		cout << l << " ";
	}
	cout << endl;

	return 0;
}

void elimDups(list<string> &lstr)
{
	lstr.sort();
	auto eu = unique(lstr.begin(), lstr.end());
	lstr.erase(eu, lstr.end());
}