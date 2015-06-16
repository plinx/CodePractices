#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string lt = "([{<", rt = ")]}>";
	string str;
	stack<char> s;
	int n;
	size_t i;

	cin >> n;
	while (n--)
	{
		cin >> str;
		while (!s.empty()) s.pop();

		for (i = 0; i < str.length(); i++)
		{
			if (lt.find(str[i]) < lt.length())
			{
				s.push(str[i]);
			}
			else if (rt.find(str[i]) < rt.length())
			{
				if (s.empty()) break;
				if (s.top() == lt[rt.find(str[i])]) s.pop();
			}
		}

		if (s.empty() && str.length() == i)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}

	std::system("pause");
	return 0;
}
