#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, op, val;

	cin >> n;
	while (n--)
	{
		cin >> op;
		if (op == 1) {
			cin >> val;
			q.push(val);
		}
		else if (op == 2) {
			if (q.empty()) {
				cout << "impossible!" << endl;
				return 0;
			}
			//cout << q.front() << endl;
			q.pop();
		}
	}

	if (q.empty()) {
		cout << "impossible!" << endl;
	}
	else {
		cout << q.front() << endl;
	}

	return 0;
}
