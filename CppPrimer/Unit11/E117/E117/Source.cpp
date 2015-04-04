#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, vector<string>> home;
	vector<string> vchild;
	string family_name;
	string child_name;

	cout << "Enter family_name : ";
	while (cin >> family_name)
	{
		cout << "Enter child_names : ";
		cin.clear();
		while (cin >> child_name)
		{
			vchild.push_back(child_name);
		}
		home[family_name] = vchild;
		vchild.clear();
		cout << "Enter family_name : ";
		cin.clear();
	}

	for (auto &h : home)
	{
		cout << "Family Name : " << h.first << endl;
		cout << "Child Name : ";
		for (auto &c : h.second)
		{
			cout << c << " ";
		}
		cout << endl;
	}

	return 0;
}