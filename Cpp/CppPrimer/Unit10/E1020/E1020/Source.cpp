#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> vstr = {
		"asdf", "fdafbasf", "ewrsa", "12345sad", "12345"
	};
	auto cnt = count_if(vstr.begin(), vstr.end(),
		[](const std::string &s) { return s.size() > 6; });

	std::cout << "Number of length large than 6 :" << cnt << std::endl;
	return 0;
}
