#ifndef UnitTest_h
#define UnitTest_h

void insert_test()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int ans[] = { 1, 2, 3, 4, 5, 6 };
	insert_sort(arr, 6);
	assert(arr[0] == ans[0]);
	assert(arr[5] == ans[5]);
	for (int i = 0; i < 5; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[5]);
}

//2.1-1
void e211()
{
	int arr[] = { 31, 41, 59, 26, 41, 58 };
	int ans[] = { 26, 31, 41, 41, 58, 59 };
	insert_sort(arr, 6);
	assert(arr[0] == ans[0]);
	assert(arr[5] == ans[5]);
	for (int i = 0; i < 5; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[5]);
}

//2.1-2
void e212()
{
	int arr[] = { 31, 41, 59, 26, 41, 58 };
	int ans[] = { 59, 58, 41, 41, 31, 26 };
	insert_sort_up(arr, 6);
	assert(arr[0] == ans[0]);
	assert(arr[5] == ans[5]);
	for (int i = 0; i < 5; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[5]);
}

//2.1-3
template <typename T>
int find(T A[], int n, T elem)
{
	for (int i = 0; i < n; i++)
		if (A[i] == elem) return i;

	return -1;
}

void e213()
{
	int arr[] = { 1, 3, 5, 2, 4, 6 };
	assert(find(arr, 6, 5) == 2);
	printf("elem index : %d\n", find(arr, 6, 5));
}

//2.1-4
int* get_sum(int A[], int na, int B[], int nb)
{
	int n;
	if (na < nb)
		n = nb + 1;
	else
		n = na + 1;
	int* C = new int[n];
	for (int i = 0; i < n; i++)
		C[i] = 0;

	int inc = 0, sum;
	for (int i = 1; i != n; i++)
	{
		sum = 0;
		if (i <= na && i <= nb)
			sum = inc + A[na - i] + B[nb - i];
		else if (i <= nb && na < i)
			sum = inc + B[nb - i];
		else if (i <= na && nb < i)
			sum = inc + A[na - i];
		else
			sum = inc;

		C[n - i] = sum % 2;
		inc = 0;
		if (sum > 1) inc = 1;
	}

	return C;
}

void e214()
{
	int A[] = { 1, 0, 1, 1, 0, 0, 1, 0 };
	int B[] = { 1, 0, 1, 1, 1 };
	int* C = get_sum(A, 8, B, 5);
	assert(C[7] != 1);
	for (int i = 0; i < 8; i++)
		printf("%d, ", C[i]);
	printf("%d\n", C[8]);

}

//2.2-1
//theta(n^3)

//2.2-2
void e222()
{
	int arr[] = { 5, 2, 4, 6, 1, 3, 9, 7, 8 };
	int ans[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	select_sort(arr, 9);
	assert(arr[5] == ans[5]);
	for (int i = 0; i < 8; i++) printf("%d, ", arr[i]);
	printf("%d\n", arr[8]);
	
}

//2.2-3
//skip

//2.2-4
//skip

//2.3-1
/*
  A = {3, 41, 52, 26, 38, 57, 9, 49};
  => 3, 41, 52, 26 | 38, 57, 9, 49
  => 3, 41 | 52, 26 | 38, 57 | 9, 49 
  => return from button
  => 3, 41 | 26, 52 | 38, 57, 9, 49
  => 3, 26, 41, 52 | 9, 38, 49, 57
  => 3, 9, 26, 38, 41, 49, 52, 57
*/

//2.3-2
void e232()
{
	clock_t start, t1, t2;
	int ans[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = 100000, num;
	int arr[100000] = { 0 };
	int narr[100000] = { 0 };
	for (int i = 0; i < size; i++)
	{
		num = rand() % size;
		arr[i] = narr[i] = num;
	}

	start = clock();
	merge_sort_recursive(arr, 0, size - 1);
	t1 = clock() - start;

	start = clock();
	merge_sort_nonrecursive(arr, size);
	t2 = clock() - start;

	/*for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%d, ", arr[i]);
	}*/
	printf("Run time : %d, %d ms\n", t1, t2);
}

//2.3-3
/*
  T(n) = nlgn
  T(2) = 2lg2 = 2
  T(n) = 2T(n/2) + n = 2 * n/2 lg(n/2) + n = nlgn - n + n = nlgn
*/

//2.3-4
//skip

//



#endif