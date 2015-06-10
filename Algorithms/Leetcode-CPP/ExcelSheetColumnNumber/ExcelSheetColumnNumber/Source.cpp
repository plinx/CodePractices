#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ret = 0;
		for (auto &c : s)
		{
			ret = ret * 26 + static_cast<int>(c)-64;
		}

		return ret;
	}
};

int main()
{
	Solution ans;
	vector<string> vstr = { "A", "B", "AB", "BA", "CA" };

	for (auto &v : vstr)
	{
		cout << ans.titleToNumber(v) << endl;
	}

	return 0;
}