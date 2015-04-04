#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
	if (!argv[1])
	{
		std::cout << "No input file." << std::endl;
		return -1;
	}
	std::ifstream ifs(argv[1]);
	std::istream_iterator<std::string> int_it(ifs), eof;
	std::vector<std::string> vstr(int_it, eof);

	for (auto &s : vstr)
	{
		std::cout << s << std::endl;
	}

	return 0;
}