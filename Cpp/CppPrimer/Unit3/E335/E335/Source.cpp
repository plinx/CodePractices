#include <iostream>
#include <iterator>
using std::begin;
using std::end;

int main()
{
	int arr[10];
	int *b = begin(arr), *e = end(arr);

	while (b != e) {
		*b = 0;
		++b;
	}

	for (int i = 0; i < 10; ++i)
		std::cout << "arr[" << i << "] :" << arr[i] << " ";

	std::cout << std::endl;

	return 0;
}