#ifndef UnitTest_h
#define UnitTest_h

void test_quicksort()
{
	int A[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	quicksort(A, 0, len(A) - 1);
	printf("test_quicksort : ");
	for (int i = 0; i < len(A) - 1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[len(A) - 1]);
}

void e711()
{
	int A[] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };
	quicksort(A, 0, len(A) - 1);
	printf("e711 : ");
	for (int i = 0; i < len(A) - 1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[len(A) - 1]);
}

void e712()
{
	int A[] = { 2, 2, 2, 2, 2, 2, 2, 2 };
	printf("e712 : %d\n", partition(A, 0, len(A) - 1));
}

void e714()
{
	int A[] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };
	quicksort_up(A, 0, len(A) - 1);
	printf("e711 : ");
	for (int i = 0; i < len(A) - 1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[len(A) - 1]);
}

void test_quicksort_random()
{
	int A[] = { 13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11 };
	quicksort_random(A, 0, len(A) - 1);
	printf("test_quicksort_random : ");
	for (int i = 0; i < len(A) - 1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[len(A) - 1]);
}

//7.3-1
//随机化算法不能改变最坏运行时间，但是能降低最坏情况发生的机率

//7.3-2
//best : O(logn)
//worst : O(n)
//avarage : theta(logn)

#endif

