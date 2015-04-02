#include <iostream>
#include <list>
#include <forward_list>

int main()
{
	std::list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto liter = lst.begin();
	while (liter != lst.end())
	{
		if (*liter % 2)
		{
			liter = lst.insert(liter, *liter);
			++liter;	// list and forward_list cann't random access
			++liter;	// liter += 2 is error.
		}
		else
		{
			liter = lst.erase(liter);
		}
	}

	std::cout << "list : ";
	for (auto &l : lst)
	{ 
		std::cout << l << " ";
	}
	std::cout << std::endl;

	auto prev = flst.cbefore_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr % 2)
		{
			curr = flst.insert_after(prev, *curr);
			++curr;
			prev = curr;
			++curr;
		}
		else
		{
			curr = flst.erase_after(prev);
		}
	}

	std::cout << "forward_list : ";
	for (auto &fl : flst)
	{
		std::cout << fl << " ";
	}
	std::cout << std::endl;

	return 0;
}