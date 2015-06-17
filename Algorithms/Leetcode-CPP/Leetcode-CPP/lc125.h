#ifndef lc125_h
#define lc125_h

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		if (s.size() < 2) return true;

		int i = 0, j = s.size() - 1;
		for (int i = 0; i < s.size(); i++)
			if (96 < s[i] && s[i] < 123) s[i] -= 32;

		while (i < j)
		{
			if (s[i] < 48 || (57 < s[i] && s[i] < 65) || 90 < s[i])
			{
				i++; continue;
			}
			if (s[j] < 48 || (57 < s[j] && s[j] < 65) || 90 < s[j])
			{
				j--; continue;
			}
			cout << i << "," << j << endl;
			cout << s[i] << ", " << s[j] << endl;

			if (s[i] == s[j])
			{
				i++; j--;
			}
			else
			{
				return false;
			}
		}
		
		//cout << s << endl;
		return true;
	}
};

int lc125()
{
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	string s3 = "1a2";
	string s4 = "0k.;r0k";
	string s5 = "ab@a";

	cout << Solution().isPalindrome(s5) << endl;

	system("pause");
	return 0;
}

#endif