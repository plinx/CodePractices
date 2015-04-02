#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << "old array : ";
	for (auto i = ivec.begin(); i != ivec.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "new array : ";
	for (auto i = ivec.begin(); i != ivec.end(); ++i) {
		*i = *i * 2;
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}