#ifndef sorts_h
#define sorts_h

#include <memory>

template <typename E>
void insertSort(E A[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0; j--)
			if (A[j] < A[j - 1]) std::swap(A[j], A[j - 1]);
}

template <typename E>
void bubbleSort(E A[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (A[j] < A[j - 1]) std::swap(A[j], A[j - 1]);
}

template <typename E>
void selectSort(E A[], int n)
{
	int lowindex;
	for (int i = 0; i < n - 1; i++)
	{
		lowindex = i;
		for (int j = n - 1; j > i; j--)
			if (A[j] < A[lowindex]) lowindex = j;
		std::swap(A[i], A[lowindex]);
	}
}

template <typename E>
void shellInsert(E A[], int n, int step)
{
	for (int i = step; i < n; i++)
		for (int j = n - 1; j >= step; j -= step)
			if (A[j] < A[j - 1]) std::swap(A[j], A[j - 1]);
}

template <typename E>
void shellSort(E A[], int n)
{
	for (int i = n / 2; i > 2; i /= 2)
		for (int j = 0; j < i; j++)
			shellInsert(A, n - j, i);
		shellInsert(A, n, 1);
}

template <typename E>
void mergeSort(E A[], E tmp[], int left, int right)
{
	if (left == right) return;
	int mid = (left + right) / 2;

	mergeSort(A, tmp, left, mid);
	mergeSort(A, tmp, mid + 1, right);

	for (int t = 0; t < mid + 1; t++) tmp[t] = A[t];

	int i, j, k;
	i = mid + 1;
	j = k = 0;
	while (i <= right && j < mid + 1)
	{
		if (A[i] < tmp[j]) 
			A[k++] = A[i++];
		else
			A[k++] = tmp[j++];
	}
	while (i <= right) A[k++] = A[i++];
	while (j < mid + 1) A[k++] = tmp[j++];
}

#endif