#ifndef t5_h
#define t5_h

#include <stack>

struct Link
{
	Link(int ival) : val(ival), next(nullptr) {}

	int val;
	Link* next;
};

void print_Link_byStack(Link* pHead)
{
	std::stack<Link*> nodes;

	Link* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while (!nodes.empty())
	{
		printf("%d ", nodes.top()->val);
		nodes.pop();
	}
	printf("\n");
}

void print_Link_Recursive(Link* head)
{
	if (head == nullptr) return;
	if (head->next != nullptr)
		print_Link_Recursive(head->next);
	printf("%d ", head->val);
}

void t5()
{
	int arr[] = { 3, 4, 1, 5 };
	Link head(0);
	Link* temp = &head;

	for (int i = 0; i < 4; i++)
	{
		temp->next = new Link(arr[i]);
		temp = temp->next;
	}
	
	print_Link_byStack(&head);
	print_Link_Recursive(&head);
}

#endif