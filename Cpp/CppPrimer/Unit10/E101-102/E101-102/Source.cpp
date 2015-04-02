#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

int main()
{
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	std::list<std::string> lst = { "test", "test1", "test2", "t1", "t2", "t1" };
	
	std::cout << "value '1' in vector<int> : " 
		<< std::count(vec.begin(), vec.end(), 1) << std::endl;
	std::cout << "value \"test\" in list<string> : " 
		<< std::count(lst.begin(), lst.end(), "test") << std::endl;

	return 0;
}