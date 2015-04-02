#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using std::multiset; using std::vector;
using std::string;

int main()
{
	multiset<string> c = { "mstr1", "mstr2" };
	vector<string> v = { "vstr1", "vstr2" };

	std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
	//std::copy(v.begin(), v.end(), std::back_inserter(c));	// multiset don't have push_back
	std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
	std::copy(c.begin(), c.end(), std::back_inserter(v));

	return 0;
}