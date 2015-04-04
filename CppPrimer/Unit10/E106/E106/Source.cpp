#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
	std::vector<int> vec(10, 1);
	fill(vec.begin(), vec.end(), 0);
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;
}