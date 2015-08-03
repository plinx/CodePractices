#include <iostream>

void printchar(char* a, char b)
{
	static int i = 1;
	*a = *a + i++;
	b = b + i++;
	std::cout << *a << b;
}

void moneychicken()
{
	int money = 100;
	for (int n1 = 1; n1 < money / 5; ++n1)
	{
		for (int n2 = 1; n2 < money / 3; ++n2)
		{
			int n3 = money - n1 - n2;
			if (100 == (n1 * 5 + n2 * 3 + n3 / 3) && n3 % 3 == 0)
				printf("%d %d %d\n", n1, n2, n3);

		}
	}
}

void quicksort(int A[], int n)
{
	if (n < 2) return;

	int left = 0;
	int right = n;
	int lhold = left;
	int rhold = right;

	while (left < right)
	{
		if (A[left++] < A[right]) lhold++;
		if (left < right)
		{
			A[left] = A[right];

		}
	}

}

int main()
{
	int arr[] = { 1, 5, 9, 4, 2, 3, 8, 7, 0, 6 };
	char c = 'A', d = 'a';
	printchar(&c, d);
	std::cout << c << d << std::endl;

	moneychicken();

	system("pause");
	return 0;
}
