#include <iostream>

using namespace std;

int main()
{
	int joseph[14] = { 0, 2 };
	int k, m, n;
	int kill, pos;
	int i;

	while (cin >> k)
	{
		if (k == 0)
			break;

		if (joseph[k])
		{
			cout << joseph[k] << endl;
			continue;
		}

		n = 2 * k;
		m = k + 1;
		pos = 0;
		for (int i = 1; i <= k; i++) 
		{
			pos = (pos + m - 1) % (n - i + 1);
			if (pos < k)
			{
				i = 0;
				pos = 0;
				m++;
			}
		}
		joseph[k] = m;
		cout << m << endl;
	}

	return 0;
}

