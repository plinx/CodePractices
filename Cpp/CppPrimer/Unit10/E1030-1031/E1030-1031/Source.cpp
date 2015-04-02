#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
	std::istream_iterator<int> is_it(std::cin), eof;
	std::ostream_iterator<int> os_it(std::cout, " ");
	std::vector<int> vec(is_it, eof);

	sort(vec.begin(), vec.end());
	std::cout << "copy to ostream_iterator : " << std::endl;
	copy(vec.begin(), vec.end(), os_it);
	std::cout << std::endl;
	std::cout << "unique_copy to ostream_iterator : " << std::endl;
	unique_copy(vec.begin(), vec.end(), os_it);
	std::cout << std::endl;

	return 0;
}