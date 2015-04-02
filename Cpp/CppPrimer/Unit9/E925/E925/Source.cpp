#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	auto elem1 = vec.begin() + 1;
	auto elem2 = elem1;
	vec.erase(elem1, elem2);	// would do nothing to vec

	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	elem2 = vec.end();
//	elem1 = elem2;		// both are vec.end(), would do nothing to vec
	vec.erase(elem1, elem2);
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}