#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	vector<string> vstr;
	set<string> sstr;
	string word;

	while (cin >> word)
	{
		if (find(vstr.begin(), vstr.end(), word) == vstr.end())
			vstr.push_back(word);
		sstr.insert(word);
	}

	cout << "vector<string> :" << endl;
	for (auto &v : vstr)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "set<string> :" << endl;
	for (auto &s : sstr)
	{
		cout << s << " ";
	}
	cout << endl;
	cout << endl;

	return 0;
}