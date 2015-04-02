#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using std::vector; using std::string; using std::multimap; using std::pair;
using std::cin; using std::cout; using std::endl;

int main()
{
	multimap<string, vector<string>> family;
	pair<string, vector<string>> fpair;
	string fname;
	string cname;
	
	cout << "Enter family name : ";
	while (cin >> fname)
	{
		cout << "Enter child name : ";
		while (cin >> cname)
		{
			family.insert({ fname, { cname } });
		}
		cin.clear();
		cout << "Enter family name : ";
	}

	for (auto &f : family)
	{
		cout << "Family name : " << f.first << endl;
		for (auto &c : f.second)
		{
			cout << "Child name : " << c << endl;
		}
	}

	return 0;
}