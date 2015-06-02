#include <iostream>
#include "sorts.h"

int main()
{
	int arr[] = { 1, 3, 5, 2, 4, 6, 0, 9, 8 };
	int tmp[9] = {};
	mergeSort<int>(arr, tmp, 0, 8);

	/*
	insertSort<int>(arr, 9);
	bubbleSort<int>(arr, 9);
	selectSort<int>(arr, 9);
	shellSort<int>(arr, 9);
	*/

	for (auto a : arr)
		std::cout << a << ", ";
	std::cout << std::endl;

	system("pause");
	return 0;
}
