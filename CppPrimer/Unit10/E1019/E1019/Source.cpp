#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void biggies(std::vector<std::string>&, std::vector<std::string>::size_type);

int main()
{
	std::vector<std::string> vstr = {
		"000", "001", "012", "1231", "1312132", "112311", "97123"
	};
	biggies(vstr, 4);

	return 0;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto eu = unique(words.begin(), words.end());
	words.erase(eu, words.end());

	stable_sort(words.begin(), words.end(),
		[](const std::string &a, const std::string &b) { return a.size() < b.size(); });

	auto first = stable_partition(words.begin(), words.end(),
		[sz](const std::string &s) { return s.size() < sz; });

	for_each(first, words.end(),
		[](const std::string &s) {std::cout << s << " "; });
	std::cout << std::endl;
}