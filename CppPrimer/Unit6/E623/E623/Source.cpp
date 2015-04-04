#include <iostream>

void print(int);
void print(int[], size_t);

int main()
{
	int i = 0;
	int j[4] = { 0, 1, 2, 3};

	print(i);
	print(j, 4);

	return 0;
}

void print(int i)
{
	std::cout << "i : " << i << std::endl;
}

void print(int arr[], size_t size)
{
	for (size_t i = 0; i != size; ++i) {
		std::cout << "arr[" << i << "] : " << arr[i] << std::endl;
	}
}