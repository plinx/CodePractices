#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std::placeholders;
bool check_size(int, std::string);


int main()
{
	std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::string str;
	std::cout << "Enter string : ";
	std::cin >> str;
	std::cout << "String length is " << str.size() << std::endl;

	auto first = find_if(vi.begin(), vi.end(),
		bind(check_size, _1, str));

	std::cout << "Number large than string length :" << std::endl;
	while (first != vi.end())
	{
		std::cout << *first << " ";
		++first;
	}
	std::cout << std::endl;

	return 0;
}

bool check_size(int si, std::string str)
{
	return si > str.size();
}