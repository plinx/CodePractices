#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vi = { 0, 1, 2, 3, 4, 3, 1, 4, 5, 6 };
	std::list<int> li;

	unique_copy(vi.begin(), vi.end(), back_inserter(li));
	for (auto &v : vi)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}
