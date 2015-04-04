#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> lst;
	auto rv = vec.crbegin() + 3;

	while (rv != vec.crend() - 2)
	{
		lst.push_back(*rv);
		++rv;
	}

	for (auto &l : lst)
	{
		cout << l << " ";
	}
	cout << endl;

	return 0;
}