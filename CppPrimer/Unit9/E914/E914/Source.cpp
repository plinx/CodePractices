#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
	std::list<const char *> lst = { "str1", "str2" };
	std::vector<std::string> vecs;
	vecs.assign(lst.begin(), lst.end());

	for (auto &v : vecs)
	{
		std::cout << v << std::endl;
	}
	return 0;
}