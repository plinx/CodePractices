#include <iostream>

using namespace std;

int main()
{
	float money, sum;

	sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cin >> money;
		sum += money;
	}

	cout << sum / 12 << endl;

	return 0;
}