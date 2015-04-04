#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> flst = { 0, 1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 9 };

	auto prev = flst.cbefore_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr % 2)
		{
			curr = flst.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}

	for (auto &f : flst)
	{
		std::cout << f << " ";
	}
	std::cout << std::endl;
	return 0;
}