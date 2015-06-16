#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int n, op, val;

	cin >> n;
	while (n--)
	{
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> val;
			s.push(val);
			break;
		case 2:
			if (s.empty())
			{
				cout << "impossible!" << endl;
				return 0;
			}
			s.pop();
			break;
		case 3:
			if (s.empty())
			{
				cout << "impossible!" << endl;
				return 0;
			}
			cout << s.top() << endl;
			break;
		}
	}

	system("pause");

	return 0;
}