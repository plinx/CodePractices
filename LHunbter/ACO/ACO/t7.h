#ifndef t7_h
#define t7_h

#include <stack>
#include <queue>

class sQueue
{
public:
	void append(const int val);
	int pop();
	bool empty();
private:
	std::stack<int> instack;
	std::stack<int> outstack;
};

void sQueue::append(const int val)
{
	instack.push(val);
}

int sQueue::pop()
{
	if (outstack.empty())
	{
		while (!instack.empty())
		{
			outstack.push(instack.top());
			instack.pop();
		}
	}
	if (outstack.empty())
	{
		printf("sQueue is empty.\n");
		return -2147483647L;
	}
	int result = outstack.top();
	outstack.pop();
	return result;
}

bool sQueue::empty()
{
	return instack.empty() && outstack.empty();
}

class qStack
{
	std::queue<int> q1;
	std::queue<int> q2;
public:
	void push(int x)
	{
		if (q1.empty())
			q2.push(x);
		else
			q1.push(x);
	}

	int pop()
	{
		if (q1.empty() && q2.empty())
		{
			printf("qStack is empty.\n");
			return -2147483647L;
		}

		int result;
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			result = q2.front();
			q2.pop();
		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			result = q1.front();
			q1.pop();
		}
		return result;
	}
};


void t7()
{
	sQueue queue;
	for (int i = 0; i < 5; i++)
		queue.append(i);
	queue.pop();
	queue.pop();
	for (int i = 0; i < 5; i++)
		queue.append(i);

	while (!queue.empty())
		printf("%d ", queue.pop());
	printf("\n");

	qStack stack;
	stack.push(1);
	stack.push(2);
	printf("%d ", stack.pop());
	stack.push(3);
	stack.push(4);
	printf("%d ", stack.pop());
	printf("%d ", stack.pop());
	printf("%d\n", stack.pop());
}

#endif