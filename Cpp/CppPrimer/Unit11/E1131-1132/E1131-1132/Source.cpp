#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using std::multimap; using std::string; 
using std::cout; using std::endl;

int main()
{
	multimap<string, string> authors = {
		{ "a", "book1" }, { "a", "book2" }, { "b", "book1" }, { "c", "nobook" }
	};

	string strb = "b";
	string strd = "d";

	auto ret = authors.find(strb);
	if (ret != authors.end())
	{
		authors.erase(strb);
	}
	ret = authors.find(strd);
	if (ret != authors.end())
	{
		authors.erase(strd);
	}
	string pre_author;

	for (auto &a : authors)
	{
		if (a.first != pre_author)
		{
			pre_author = a.first;
			cout << "Author : " << a.first << endl;
			cout << "Books : " << a.second << " ";
		}
		else
		{
			cout << a.second << endl;
		}
	}
	cout << endl;

	return 0;
}