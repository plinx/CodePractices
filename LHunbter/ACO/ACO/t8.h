#ifndef t8_h
#define t8_h

#include <random>

int partition(int A[], int left, int right)
{
	std::random_device rd;
	int pivot = rd() % (right - left + 1) + left;
	std::swap(A[pivot], A[right]);
	int j = left;
	for (int i = left; i < right; i++)
		if (A[i] <= A[right]) std::swap(A[i], A[j++]);
	std::swap(A[j], A[right]);

	return j;
}

void quicksort(int A[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(A, left, right);
		quicksort(A, left, pivot - 1);
		quicksort(A, pivot, right);
	}
}

void t8()
{
	int arr[] = { 1, 9, 4, 2, 1, 65, 4, 57, 43, 31};
	//partition(arr, 0, 10);
	//partition(arr, 0, 10);

	quicksort(arr, 0, 9);
	for (auto &a : arr)
		printf("%d ", a);
	printf("\n");
}

#endif