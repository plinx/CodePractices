#ifndef qsort_h
#define qsort_h

template <typename T, int size>
inline int len(const T(&A)[size]) { return size; }

inline int randint(const int start, const int end)
{
	int i = rand() % abs(end - start + 1);
	if (end < start) return end + i;
	return start + i;
}

template <typename T>
int partition(T A[], int left, int right)
{
	int i = left;
	for (int j = left; j < right; j++)
		if (A[j] <= A[right]) std::swap(A[j], A[i++]);
	std::swap(A[i], A[right]);

	if (A[left] == A[right]) return i / 2;

	return i;
}

template <typename T>
void quicksort(T A[], int left, int right)
{
	if (left < right)
	{
		int mid = partition(A, left, right);
		quicksort(A, left, mid - 1);
		quicksort(A, mid, right);
	}
}

template <typename T>
int partition_up(T A[], int left, int right)
{
	int i = left;
	for (int j = left; j < right; j++)
		if (A[j] > A[right]) std::swap(A[j], A[i++]);
	std::swap(A[i], A[right]);

	if (A[left] == A[right]) return i / 2;

	return i;
}

template <typename T>
void quicksort_up(T A[], int left, int right)
{
	if (left < right)
	{
		int mid = partition_up(A, left, right);
		quicksort_up(A, left, mid - 1);
		quicksort_up(A, mid, right);
	}
}

template <typename T>
int partition_random(T A[], int left, int right)
{
	int i = randint(left, right);
	std::swap(A[i], A[right]);

	return partition(A, left, right);
}

template <typename T>
void quicksort_random(T A[], int left, int right)
{
	if (left < right)
	{
		int mid = partition_random(A, left, right);
		quicksort_random(A, left, mid - 1);
		quicksort_random(A, mid, right);
	}
}

#endif