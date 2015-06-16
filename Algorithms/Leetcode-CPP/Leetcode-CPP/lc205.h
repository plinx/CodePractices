#ifndef lc205_h
#define lc205_h

#include <cstdio>
#include <string>

using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		int t1[256] = { 0 };
		int t2[256] = { 0 };

		for (size_t i = 0; i < s.size(); i++)
		{
			if (t1[s[i]] != t2[t[i]]) return false;
			t1[s[i]] = i + 1;
			t2[t[i]] = i + 1;
		}

		return true;
	}
};

int lc205()
{
	string str1 = "aba";
	string str2 = "baa";

	printf("%s\n", Solution().isIsomorphic(str1, str2) ? "True" : "False");
	system("pause");
	return 0;
}

#endif