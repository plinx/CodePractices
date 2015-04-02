#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std::placeholders;
bool large_than_5(std::string&);

int main()
{
	std::vector<std::string> vstr = {
		"1fdfas", "24fas", "asdf", "1", "fasf2"
	};

	auto wc = count_if(vstr.begin(), vstr.end(),
		//[](const std::string &s) {return s.size() > 5; });
		bind(large_than_5, _1));

	std::cout << "Length large than 5 : " << wc << std::endl;

	return 0;
}

bool large_than_5(std::string &str)
{
	return str.size() > 5;
}
