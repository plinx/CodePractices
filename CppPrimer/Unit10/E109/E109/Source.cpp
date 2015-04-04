#include <iostream>
#include <vector>
#include <algorithm>

void elimDups(std::vector<int> &);

int main()
{
	std::vector<int> vec = { 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 5, 4, 3, 2, 1 };
	elimDups(vec);
	std::cout << "after elimDups :\t";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}

void elimDups(std::vector<int> &vec)
{
	sort(vec.begin(), vec.end());
	std::cout << "after sort :\t";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	auto eu = unique(vec.begin(), vec.end());
	std::cout << "after unique :\t";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	vec.erase(eu, vec.end());
}