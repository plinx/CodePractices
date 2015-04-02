#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<string, size_t> wcnt;
	set<string> exclude = {
//		"The", "But", "And", "Or", "An", "A",	// no use after tolower()
		"the", "but", "and", "or", "an", "a"
	};
	string word;

	while (cin >> word)
	{
		for (auto &w : word)
		{
			w = tolower(w);
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		if (exclude.find(word) == exclude.end())
		{
			++wcnt[word];
		}
	}

	for (auto &w : wcnt)
	{
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time") << endl;
	}

	return 0;
}