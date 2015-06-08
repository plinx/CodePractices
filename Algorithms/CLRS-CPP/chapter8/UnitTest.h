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

void test_radix_sort_int()
{
	int A[] = { 421, 240, 35, 532, 305, 430, 134 };
	radix_sort_int(A, len(A), 3);
	for (int i = 0; i < len(A) - 1; i++)
		printf("%d, ", A[i]);
	printf("%d\n", A[len(A) - 1]);
}

void test_radix_sort_str()
{
	std::string str[] = {
		"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TAB",
		"BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"
	};
	radix_sort_str(str, len(str), 3);
	for (int i = 0; i < len(str) - 1; i++)
		printf("%s, ", str[i].c_str());
	printf("%s\n", str[len(str) - 1].c_str());
}
#endif
