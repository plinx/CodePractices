#ifndef lc2_h
#define lc2_h

#include <cstdio>
#include <cstdlib>

class ListNode
{
public:
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode* l3 = new ListNode(0);
		ListNode* pl1 = l1;
		ListNode* pl2 = l2;
		ListNode* pl3 = l3;

		int val, inc = 0;
		while (pl1 != NULL && pl2 != NULL)
		{
			val = pl1->val + pl2->val + inc;
			inc = val / 10;
			pl3->next = new ListNode(val % 10);
			pl1 = pl1->next;
			pl2 = pl2->next;
			pl3 = pl3->next;
		}

		while (pl1 != NULL)
		{
			val = pl1->val + inc;
			inc = val / 10;
			pl3->next = new ListNode(val % 10);
			pl1 = pl1->next;
			pl3 = pl3->next;
		}

		while (pl2 != NULL)
		{
			val = pl2->val + inc;
			inc = val / 10;
			pl3->next = new ListNode(val % 10);
			pl2 = pl2->next;
			pl3 = pl3->next;
		}

		if (inc != 0)
			pl3->next = new ListNode(inc);

		return l3->next;
	}
};

int lc2()
{
	ListNode* l1 = new ListNode(0);
	ListNode* l2 = new ListNode(0);
	int list1[] = { 2, 4, 3 }, list2[] = { 5, 6, 4 };
	ListNode* tmp = l1;
	for (auto l : list1)
	{
		tmp->next = new ListNode(l);
		tmp = tmp->next;
	}

	tmp = l2;
	for (auto l : list2)
	{
		tmp->next = new ListNode(l);
		tmp = tmp->next;
	}


	auto result = Solution().addTwoNumbers(l1->next, l2->next);

	while (result != NULL)
	{
		printf("%d ", result->val);
		result = result->next;
	}
	printf("\n");
	
	system("pause");
	return 0;
}


#endif