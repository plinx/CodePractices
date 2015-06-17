#ifndef lc14_h
#define lc14_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";

		string pre = strs[0];
		int j = pre.size() - 1;
		int k;
		for (int i = 0; i < strs.size(); i++)
		{
			//cout << strs[i].size() - 1 << " " << j << endl;
			if (0 < j && (strs[i].size() - 1) < j) j = (strs[i].size() - 1);
			k = j;
			while (0 <= k)
			{
				if (pre[k] != strs[i][k]) j = k - 1;
				k--;
			}
		}

		//cout << j << endl;
		if (j == -1) return "";
		return pre.substr(0, j + 1);

	}
};

int lc14()
{
	vector<string> table = { "abca", "abc" };
	//vector<string> table = { "aca", "cba" };
	//vector<string> table = { "c", "acc", "ccc" };
	cout << Solution().longestCommonPrefix(table) << endl;

	system("pause");
	return 0;
}

#endif