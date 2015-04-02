#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<pair<string, int>> vp1, vp2, vp3;
	string word;

	while (cin >> word)
	{
		vp1.push_back(make_pair(word, word.size()));

		pair<string, int> p2(word, word.size());
		vp2.push_back(p2);

		pair<string, int> p3 = { word, word.size() };
		vp3.push_back(p3);

	}

	cout << "Make pair" << endl;
	for (auto &v : vp1)
	{
		cout << v.first << " size : " << v.second << endl;
	}
	cout << "initialize in ()" << endl;
	for (auto &v : vp2)
	{
		cout << v.first << " size : " << v.second << endl;
	}
	cout << "initialize in {}" << endl;
	for (auto &v : vp3)
	{
		cout << v.first << " size : " << v.second << endl;
	}

	return 0;
}
