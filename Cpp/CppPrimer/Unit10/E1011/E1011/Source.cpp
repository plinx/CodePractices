#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void elimDups(std::vector<std::string>&);
bool isShorter(const std::string&, const std::string&);

int main()
{
	std::vector<std::string> str = {
		"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
	};

	elimDups(str);
	for (auto &s : str)
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;

	return 0;
}

void elimDups(std::vector<std::string> &vstr)
{
	sort(vstr.begin(), vstr.end());
	auto eu = unique(vstr.begin(), vstr.end());
	vstr.erase(eu, vstr.end());
	stable_sort(vstr.begin(), vstr.end(), isShorter);
}

bool isShorter(const std::string &str1, const std::string &str2)
{
	return str1.size() < str2.size();
}