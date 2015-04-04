#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> vec;
	std::ifstream in;
	std::string buf;
	if (!argv[1]) {
		std::cout << "No input file." << std::endl;
		return -1;
	}
	in.open(argv[1]);
	std::cout << "Got string from " << argv[1] << std::endl;
	while (in >> buf)
	{
		vec.push_back(buf);
	}
	std::cout << "print string in vector<string> : " << std::endl;
	for (auto &s : vec)
	{
		std::cout << s << std::endl;
	}
	return 0;
}