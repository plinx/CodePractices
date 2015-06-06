#ifndef sorts_h
#define sorts_h

template <typename T>
void insert_sort(T A[], int n)
{
	for (int j = 1; j < n; j++)
	{
		T key = A[j];
		int i = j - 1;
		while (0 <= i && key < A[i])
			A[i + 1] = A[i--];
		A[i + 1] = key;
	}
}

template <typename T>
void insert_sort_up(T A[], int n)
{
	for (int j = 1; j < n; j++)
	{
		T key = A[j];
		int i = j - 1;
		while (0 <= i && A[i] < key)
			A[i + 1] = A[i--];
		A[i + 1] = key;
	}
}

template <typename T>
void select_sort(T A[], int n)
{
	int key;
	for (int i = 0; i < n; i++)
	{
		key = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[key]) key = j;
		std::swap(A[i], A[key]);
	}
}

template <typename T>
void merge(T A[], int left, int mid, int right)
{
	int nt = mid - left + 1;
	T* tmp = new T[nt];

	for (int i = 0; i < nt; i++) tmp[i] = A[left + i];

	int i = 0, j = mid + 1, index = left;
	while (i < nt && j <= right)
	{
		if (tmp[i] <= A[j]) A[index++] = tmp[i++];
		else A[index++] = A[j++];
	}

	while (i < nt) A[index++] = tmp[i++];
	while (j <= right) A[index++] = A[j++];
}

template <typename T>
void merge_sort_recursive(T A[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort_recursive(A, left, mid);
		merge_sort_recursive(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

template <typename T>
void merge_sort_nonrecursive(T A[], int n)
{
	if (n <= 1) return;

	int size = 2;
	int left, mid, right;
	while (size <= n)
	{
		left = 0;
		right = size - 1;
		while (right < n)
		{
			mid = (left + right) / 2;
			merge(A, left, mid, right);
			left += size;
			right += size;
		}
		size *= 2;
	}
	merge(A, 0, (size / 2) - 1, n - 1);
}



#endif