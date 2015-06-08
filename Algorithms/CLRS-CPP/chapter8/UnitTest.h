#ifndef UnitTest_h
#define UnitTest_h

//8.1-1
//minimun degree: 1

void test_count_sort()
{
	int A[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int B[8] = { 0 };
	count_sort(A, B, len(A), max_key(A) + 1);
	printf("test_count_sort : ");
	for (int i = 0; i < len(B) - 1; i++)
		printf("%d, ", B[i]);
	printf("%d\n", B[len(B) - 1]);
}

void e821()
{
	int A[] = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	int B[11] = { 0 };
	count_sort(A, B, len(A), max_key(A) + 1);
	printf("e821 : ");
	for (int i = 0; i < len(B) - 1; i++)
		printf("%d, ", B[i]);
	printf("%d\n", B[len(B) - 1]);
}

void e823()
{
	int A[] = { 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
	int B[11] = { 0 };
	count_sort_up(A, B, len(A), max_key(A) + 1);
	printf("e823 : ");
	for (int i = 0; i < len(B) - 1; i++)
		printf("%d, ", B[i]);
	printf("%d\n", B[len(B) - 1]);
}


#endif
