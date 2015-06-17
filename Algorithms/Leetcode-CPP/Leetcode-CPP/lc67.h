#ifndef lc67_h
#define lc67_h

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.size() - 1;
		int j = b.size() - 1;
		string c = "";
		char inc = '0';

		while (0 <= i && 0 <= j)
		{
			if (a[i] == b[j])
			{
				c = inc + c;
				inc = a[i];
			}
			else
			{
				c = ((inc == '1') ? '0' : '1') + c;
			}
			i--;
			j--;
		}

		while (0 <= i)
		{
			if (inc != '1')
			{
				c = a[i] + c;
			}
			else
			{
				c = ((a[i] == '1') ? '0' : '1') + c;
				inc = a[i];
			}
			i--;
		}

		while (0 <= j)
		{
			if (inc != '1')
			{
				c = b[j] + c;
			}
			else
			{
				c = ((b[j] == '1') ? '0' : '1') + c;
				inc = b[j];
			}
			j--;
		}

		if (inc != '0')
			c = "1" + c;

		return c;

	}
};

int lc67()
{
	string a = "110010";
	string b = "10111";
	cout << Solution().addBinary(a, b) << endl;

	system("pause");
	return 0;
}

#endif