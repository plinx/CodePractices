#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using std::map; using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
	map<string, size_t> wcnt;
	string word;

	while (cin >> word)
	{
		auto ret = wcnt.insert({ word, 1 });
		if (!ret.second)
			++ret.first->second;
	}

	for (auto &w : wcnt)
	{
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time") << endl;
	}

	return 0;
}