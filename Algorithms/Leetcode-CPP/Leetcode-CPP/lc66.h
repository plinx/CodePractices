#ifndef lc67_h
#define lc67_h

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = (digits.size() - 1); i >= 0; i--)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;
			}
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

int lc66()
{
	vector<int> digits = { 9, 9 };
	auto result = Solution().plusOne(digits);
	for (auto &r : result)
		cout << r << " ";
	cout << endl;

	system("pause");
	return 0;
}

#endif