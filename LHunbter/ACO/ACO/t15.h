#ifndef t15_h
#define t15_h

class ListNode
{
public:
	int val;
	ListNode* next;
};

ListNode* FindKthToTail(ListNode* head, int k)
{
	if (head == NULL || k == 0)
		return NULL;

	ListNode* pK = head;
	ListNode* pcurr = head;

	for (int i = 0; i < k - 1; ++i)
	{
		if (pcurr->next == NULL)
			return NULL;
		pcurr = pcurr->next;
	}

	while (pcurr->next != NULL)
	{
		pcurr = pcurr->next;
		pK = pK->next;
	}

	return pK;
}

void t15()
{

}

#endif
