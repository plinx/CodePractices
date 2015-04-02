#include <iostream>
#include <vector>
#include <list>

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 0; i < 11; ++i)
	{
		vec.push_back(ia[i]);
		lst.push_back(ia[i]);
	}

	auto l = lst.begin();
	while (l != lst.end())
	{
		if (*l % 2)
			l = lst.erase(l);
		else
			++l;
	}

	auto v = vec.begin();
	while (v != vec.end())
	{
		if (*v % 2 == 0)
			v = vec.erase(v);
		else
			++v;
	}

	std::cout << "vec : ";
	for (auto &vc : vec)
	{
		std::cout << vc << " ";
	}
	std::cout << std::endl;

	std::cout << "lst : ";
	for (auto &lt : lst)
	{
		std::cout << lt << " ";
	}
	std::cout << std::endl;

	return 0;
}