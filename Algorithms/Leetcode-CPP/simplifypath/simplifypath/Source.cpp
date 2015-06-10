#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string ret, tmp;
		string::size_type i, j = 0;
		stack<string> sp;

		sp.push("/");
		for (i = 1; i < path.size(); i++)
		{
			if (path[i] != '/')
			{
				tmp += path[i];
			}
			else
			{
				if (tmp == "/.." || tmp == "..") 
				{
					if (sp.top() != "/")
					{
						sp.pop();
					}
					tmp = "/";
				}
				else if (tmp == "/." || tmp == ".")
				{
					tmp = "/";
					continue;
				}
				else if (tmp == "/")
				{
					continue;
				}
				else 
				{
					if (tmp[0] == '/' && sp.top() == "/")
						sp.push(tmp.substr(1, tmp.size() - 1));
					else if (tmp != "")
						sp.push(tmp);
					tmp = "/";
				}
			}
		}
		if (tmp == "/.." || tmp == "..")
		{
			if (sp.size() > 1)
				sp.pop();
		}
		else if (tmp != "/." && tmp != "." && tmp != "/")
		{
			if (tmp[0] == '/' && sp.top() == "/")
				sp.push(tmp.substr(1, tmp.size() - 1));
			else
				sp.push(tmp);
		}
		while (sp.size() != 0)
		{
			ret = sp.top() + ret;
			sp.pop();
		}
		return ret;
	}
};

int main()
{
	Solution lc;
	string test1 = "/home/";
	string test2 = "/a/./b/../../c/";
	string itest;

	while (cin >> itest)
		cout << lc.simplifyPath(itest) << endl;


	return 0;
}