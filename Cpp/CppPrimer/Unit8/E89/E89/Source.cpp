#include <iostream>
#include <sstream>
#include <string>

std::istream &get_input(std::istream &is);

int main()
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream istr(line);
	get_input(istr);
	return 0;
}

std::istream &get_input(std::istream &is)
{
	std::string s;
	auto old_state = is.rdstate();
	is.clear();
	std::cout << "Enter data :" << std::endl;
	while (is >> s)
	{
		std::cout << "Got :" << s << std::endl;
	}
	is.setstate(old_state);
	return is;
}
