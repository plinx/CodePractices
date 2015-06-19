#ifndef lc225_h
#define lc225_h

#include <iostream>
#include <queue>

using namespace std;

class Stack
{
	queue<int> q;
public:
	void push(int x)
	{
		queue<int> tmp;
		tmp.push(x);
		while (!q.empty())
		{
			tmp.push(q.front());
			q.pop();
		}
		while (!tmp.empty())
		{
			q.push(tmp.front());
			tmp.pop();
		}
	}

	void pop()
	{
		q.pop();
	}

	int top()
	{
		return q.front();
	}

	bool empty()
	{
		return q.empty();
	}
};

int lc225()
{
	Stack s;
	s.push(1); s.push(2); s.push(3);
	s.pop(); s.pop(); s.pop();

	cout << !s.empty() << endl;

	system("pause");

	return 0;
}

#endif