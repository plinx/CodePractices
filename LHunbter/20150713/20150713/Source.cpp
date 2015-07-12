#include <cstdio>
#include <cstdlib>

typedef union {
	long i;
	int k[5];
	char c;
}DATE;

struct data {
	int cat;
	DATE cow;
	double dog;
}too;

DATE max;

int main()
{
	printf("%d, %d, %d\n", sizeof(DATE), sizeof(struct data),
		sizeof(max));
	
	system("pause");
	return 0;
}