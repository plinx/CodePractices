#ifndef lc202_h
#define lc202_h

#include <cstdio>
#include <cstdlib>
#include <cmath>

class Solution
{
public:
	bool isHappy(int n)
	{
		int sum = 0, ret = n;

		while (ret != 0)
		{
			sum += static_cast<int>(pow((ret % 10), 2));
			ret /= 10;
			if (ret == 0)
			{
				if (6 < sum)
				{
					printf("%d, ", sum);
					ret = sum;
					sum = 0;
				}
				else // sum < 6
				{
					if (sum == 1) return true;
					return false;
				}
			}
		}

		return false;
	}
};

int lc202()
{
	Solution().isHappy(7);
	system("pause");
	return 0;
}

#endif