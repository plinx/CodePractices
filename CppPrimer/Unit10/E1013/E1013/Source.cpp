#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool more_than_5(std::string&);

int main()
{
	std::vector<std::string> vstr = {
		"asdf", "as", "fasdfa", "sadf", "12354"
	};
	auto pos = partition(vstr.begin(), vstr.end(), more_than_5);

	while (pos != vstr.end())
	{
		std::cout << *pos << " ";
		++pos;
	}
	std::cout << std::endl;
	
	return 0;
}

bool more_than_5(std::string &s)
{
	return s.size() < 5;
}