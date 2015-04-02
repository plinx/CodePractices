#include <iostream>
#include <string>

using std::string;

void reset(string &str);

int main()
{
	string str;
	std::cin >> str;

	reset(str);
	std::cout << str << std::endl;

	return 0;
}

void reset(string &str)
{
	str = "default string";
}