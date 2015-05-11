#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void perm(T* arr, int N)
{
	perm(arr, N, 0);
}

template <typename T>
void perm(T* arr, int N, int index)
{
	if (N == index + 1)
	{
		for (int i = 0; i < N; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	else
	{
		for (int j = index; j < N; j++)
		{
			swap(arr[j], arr[index]);
			perm(arr, N, index + 1);
			swap(arr[j], arr[index]);
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	perm(arr, sizeof(arr) / sizeof(int));

	return 0;
}