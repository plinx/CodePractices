#include <cstdio>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	int r = 1;
	while (r)
	{
		r = a % b;
		a = b;
		b = r;
	}
	printf("%d", a);
	return 0;
}