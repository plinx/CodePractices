#include <cstdio>

int main()
{
	int n, m;
	int arr[512];
	int left, right;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &left, &right);
		int a = 0;
		for (int j = 0; j < n; j++)
		{
			if (left > arr[j])
				a++;
		}
		if (a == n)
		{
			printf("0\n");
			continue;
		}
		int b = a;
		for (int k = a; k < n; k++)
		{
			if (right > arr[k])
				b++;
		}
		printf("%d\n", b - a);
	}

	return 0;
}