#include <iostream>
#include "sorts.h"

int main()
{
	//int arr[] = { 1, 3, 5, 2, 4, 6, 0, 9, 8 };
	int arr[] = { 0, 1, 3 };
	int tmp[9] = {};

	quickSort(arr, 0, (sizeof(arr) / sizeof(int) - 1));
	/*
	insertSort<int>(arr, 9);
	bubbleSort<int>(arr, 9);
	selectSort<int>(arr, 9);
	shellSort<int>(arr, 9);
	mergeSort<int>(arr, tmp, 0, 8);
	*/

	for (auto a : arr)
		std::cout << a << ", ";
	std::cout << std::endl;

	system("pause");
	return 0;
}
