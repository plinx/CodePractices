#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi = { 0, 1, 2, 3 };
	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			// ++iter;		// without this line will become endless loop
		}
		++iter;
	}

	std::cout << "vi : ";
	for (auto &v : vi)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}