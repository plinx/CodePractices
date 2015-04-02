#include <iostream>
#include <vector>

using std::vector;

int main()
{
	vector<int> ivec1(10), ivec2(10);
	vector<int>::size_type cnt = ivec1.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec1.size(); ++ix, --cnt)
		ivec1[ix] = cnt;

	cnt = ivec2.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec2.size(); ix++, cnt--)
		ivec2[ix] = cnt;

	for (auto &iv : ivec1) {
		std::cout << iv << " ";
	}
	std::cout << std::endl;
	for (auto &iv : ivec2) {
		std::cout << iv << " ";
	}
	std::cout << std::endl;

	return 0;
}