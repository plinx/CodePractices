#ifndef heap_h
#define heap_h

int _Parent(int index) { return (index - 1) / 2; }
int _Left(int index) { return 2 * index + 1; }
int _Right(int index) { return 2 * index + 2; }

template <typename T>
void max_heapify_recursive(T A[], int n, int index)
{
	if (n < 2) return;
	int left = _Left(index);
	int right = _Right(index);
	int max = index;

	if (left < n && A[max] < A[left]) max = left;
	if (right < n && A[max] < A[right]) max = right;

	if (max != index)
	{
		//printf("%d, %d, %d, %d\n", index, left, max, right);
		//printf("%d, %d\n", A[max], A[index]);
		std::swap(A[max], A[index]);
		max_heapify_recursive(A, n, max);
	}
}

template <typename T>
void min_heapify(T A[], int n, int index)
{
	if (n < 1) return;

	int left = _Left(index);
	int right = _Right(index);
	int min = index;

	if (left < n && A[left] < A[min]) min = left;
	if (right < n && A[right] < A[min]) min = right;

	if (min != index)
	{
		std::swap(A[min], A[index]);
		min_heapify(A, n, min);
	}
}

template <typename T>
void max_heapify_nonrecursive(T A[], int n, int index)
{
	if (n < 2) return;

	int left = _Left(index);
	int right = _Right(index);
	int max = index;

//	printf("%d, %d, %d, %d\n", left, right, max, n);
	while (left < n || right < n)
	{
		if (left < n && A[max] < A[left]) max = left;
		if (right < n && A[max] < A[right]) max = right;

//		printf("%d, %d\n", A[max], A[_Parent(left)]);
		if (max != _Parent(left))
		{
			std::swap(A[max], A[_Parent(left)]);
			left = _Left(max);
			right = _Right(max);
		}
		else
		{
			break;
		}
	}
}

template <typename T>
void build_heap_recursive(T A[], int n)
{
	for (int i = n / 2; i >= 0; i--)
		max_heapify_recursive(A, n, i);
}

template <typename T>
void build_heap_nonrecursive(T A[], int n)
{
	for (int i = n / 2; i >= 0; i--)
		max_heapify_nonrecursive(A, n, i);
}

template <typename T>
void heap_sort(T A[], int n)
{
	int size = n;
	build_heap_nonrecursive(A, n);

	for (int i = n - 1; i > 0; i--)
	{
		std::swap(A[0], A[i]);
		size--;
		max_heapify_nonrecursive(A, size, 0);
	}
}

#endif