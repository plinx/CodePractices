#include <cstdio>

int main()
{
	int n;
	int arr[15][15] = { 0 };
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int min = arr[0][i];
		for (int j = 1; j < n; j++)
		{
			if (min > arr[j][i])
				min = arr[j][i];
		}
		sum += min;
	}

	printf("%d\n", sum);

	return 0;
}