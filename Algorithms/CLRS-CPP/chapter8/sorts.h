#ifndef sorts_h
#define sorts_h

template <typename T, int size>
inline int len(const T (&A)[size]) { return size; }

template <typename T, int size>
inline T max_key(const T(&A)[size])
{
	T max = A[0];
	for (int i = 1; i < size; i++)
		if (max < A[i]) max = i;
	return max;
}

template <typename T>
void count_sort(T A[], T B[], int n, int k)
{
	T* C = new T[k];
	memset(C, 0, k * sizeof(T));
	
	for (int i = 0; i < n; i++)
		C[A[i]] = C[A[i]] + 1;

	for (int i = 1; i < k; i++)
		C[i] = C[i] + C[i - 1];

	for (int j = n - 1; j > -1; j--)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

template <typename T>
void count_sort_up(T A[], T B[], int n, int k)
{
	T* C = new T[k];
	memset(C, 0, k * sizeof(T));
	for (int i = 0; i < n; i++)
		C[A[i]] = C[A[i]] + 1;

	for (int i = 1; i < k; i++)
		C[i] = C[i] + C[i - 1];

	for (int j = 0; j < n; j++)
	{
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

#endif
