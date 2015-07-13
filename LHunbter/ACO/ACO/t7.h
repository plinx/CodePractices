#ifndef t7_h
#define t7_h

#include <stack>

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
}

#endif