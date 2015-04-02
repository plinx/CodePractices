#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void ReadtoVec(const std::string fname, std::vector<std::string> &vs);

int main(int argc, char * argv[])
{
	std::vector<std::string> vstr;
	if (!argv[1])
	{
		std::cout << "No input file" << std::endl;
		return -1;
	}
	ReadtoVec(argv[1], vstr);

	for (auto &s : vstr)
	{
		std::cout << s << std::endl;
	}

	return 0;
}

void ReadtoVec(const std::string fname, std::vector<std::string> &vs)
{
	std::ifstream in(fname);
	if (in)
	{
		std::string buf;
		while (in >> buf)
		{
			vs.push_back(buf);
		}
	}
}