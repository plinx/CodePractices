#include <iostream>
#include <map>

int main()
{
	std::map<int, int> smap = { { 1, 2 } };
	auto map_it = smap.begin();

	map_it->second = 22;

	for (auto &m : smap)
	{
		std::cout << m.first << " " << m.second << std::endl;
	}

	return 0;
}