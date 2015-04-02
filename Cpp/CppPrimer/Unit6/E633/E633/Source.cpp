#include <iostream>
#include <vector>
using std::vector;

void func(vector<int> vec, int val);

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	func(vec, vec.size() - 1);

	return 0;
}

void func(vector<int> vec, int val)
{
	if (val > 0) {
		func(vec, val - 1);
		std::cout << "vec[" << val << "] : " << vec[val] << std::endl;
	} else {
		std::cout << "vec[0] : " << vec[0] << std::endl;
	}
}