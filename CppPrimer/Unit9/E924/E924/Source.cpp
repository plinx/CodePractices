#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;

	//std::cout << vec.at(0) << std::endl;		// abort() has been called
	//std::cout << vec[0] << std::endl;			// vector subscript out of range
	//std::cout << vec.front() << std::endl;	// vector iterator not dereferencable
	//std::cout << *vec.begin() << std::endl;	// vector iterator not dereferencable

	return 0;
}