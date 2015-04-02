#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> nvi1, nvi2;
	std::list<int> li;

	unique_copy(vi.begin(), vi.end(), inserter(nvi1, nvi1.begin()));
	unique_copy(vi.begin(), vi.end(), back_inserter(nvi2));
	unique_copy(vi.begin(), vi.end(), front_inserter(li));
	std::cout << "inserter :" << std::endl;
	for (auto &v : nvi1)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	std::cout << "back_inserter :" << std::endl;
	for (auto &v : nvi2)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	std::cout << "front_inserter :" << std::endl;
	for (auto &l : li)
	{
		std::cout << l << " ";
	}
	std::cout << std::endl;

	return 0;
}
