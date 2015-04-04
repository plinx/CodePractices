#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> lst = { 1, 2, 3 };
	std::vector<int> veci = { 4, 5, 6 };
	std::vector<double> vecd1(lst.begin(), lst.end());
	std::vector<double> vecd2(veci.begin(), veci.end());

	std::cout << "vector<double> 1 from list : ";
	for (auto &d : vecd1)
	{
		std::cout << d << " ";
	}
	std::cout << std::endl;

	std::cout << "vector<double> 2 from vector<int> : ";
	for (auto &d : vecd2)
	{
		std::cout << d << " ";
	}
	std::cout << std::endl;

	return 0;	
}

