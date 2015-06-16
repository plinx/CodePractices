#ifndef lc190_h
#define lc190_h

#include <cstdio>
#include <cstdlib>
#include <cmath>

class Solution
{
public:
	unsigned int reverseBits(unsigned int n) {
		int bits[32] = { 0 };
		int table[32] = { 0 };
		int ret = 0;

		for (int i = 0; i < 32; ++i) table[i] = static_cast<int>(pow(2, i));
		//for (int i = 0; i < 10; ++i) printf("%d,", table[i]);
		//printf("\n");
		for (int i = 31; i >= 0; --i)
		{
			if (table[i] <= n)
			{
				n -= table[i];
				bits[31 - i] = 1;
			}
		}

		//for (int i = 0; i < 32; ++i) printf("%d ", bits[i]);
		for (int i = 0; i < 32; ++i)
		{
			if (bits[i] != 0) ret += table[i];
		}

		return ret;
	}
};

int lc190()
{
	printf("%d\n", Solution().reverseBits(1));
	system("pause");
	return 0;
}

#endif