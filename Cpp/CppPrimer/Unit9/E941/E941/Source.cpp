#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<char> vchar = { 'h', 'e', 'l', 'l', 'o', '\0' };
	std::string str;

	for (auto &c : vchar)
	{
		str.push_back(c);
	}

	std::cout << str << std::endl;

	return 0;
}