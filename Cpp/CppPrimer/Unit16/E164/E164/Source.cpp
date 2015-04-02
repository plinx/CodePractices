#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T, typename V>
T findv(const T &begin, const T &end, const V &value)
{
	auto iter = begin;
	while (iter != end && *iter != value) ++iter;
	return iter;
}

int main()
{
	vector<int> vi = { 1, 2, 3, 4, 5, 6 };
	list<string> ls = { "1", "2", "3" };

	auto vit = findv(vi.cbegin(), vi.cend(), 4);
	cout << "Find 4 in vi : " << *vit << endl;

	auto lit = findv(ls.cbegin(), ls.cend(), "3");
	cout << "Find 3 in ls : " << *lit << endl;

	return 0;
}
