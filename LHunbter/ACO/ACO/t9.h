#ifndef t9_h
#define t9_h

int fib(int n)
{
	if (n == 0) return 0;
	if (n < 3) return 1;

	int step1 = 1;
	int step2 = 2;
	int result = 2;
	for (int i = 4; i <= n; ++i)
	{
		result = step1 + step2;
		step1 = step2;
		step2 = result;
	}

	return result;

}

void t9()
{
	for (int i = 0; i < 10; i++)
		printf("%d ", fib(i));
	printf("\n");
}

#endif