#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = { 0, 1, 2, 3 };
	auto begin = vec.begin();
	while (begin != vec.end())
	{
		++begin;
		//begin = vec.insert(begin, 42);
		vec.insert(begin, 42);	// if don't update begin, begin will be invalid
		++begin;
	}

	std::cout << "vec : ";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}