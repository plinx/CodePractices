#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, vector<pair<string, string>>> home;
	pair<string, string> child;
	string fname;
	string cname, cbirth;

	cout << "Enter family name : ";
	while (cin >> fname)
	{
		cout << "Enter child name : ";
		while (cin >> cname)
		{
			cout << "Enter " << cname << "'s birthday : ";
			cin >> cbirth;
			home[fname].push_back(make_pair(cname, cbirth));
			cout << "Enter child name : ";
		}
		cin.clear();
		cout << "Enter family name : ";
	}

	for (auto &h : home)
	{
		cout << endl << "Family name : " << h.first << endl;
		for (auto &c : h.second)
		{
			cout << c.first << " was born in " << c.second << endl;
		}
	}

	return 0;
}
