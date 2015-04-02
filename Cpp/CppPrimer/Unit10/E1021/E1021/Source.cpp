#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int li = 10;
	std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };
	auto f = [&li]{ if (li > 0) { --li; return 1; } else return 0; };

	for (auto &v : vi)
	{
		std::cout << f() << " ";
	}
	std::cout << std::endl;

	return 0;
}