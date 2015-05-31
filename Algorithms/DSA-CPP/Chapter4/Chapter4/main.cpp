#include "stdafx.h"

int main()
{
	ArrList<int> arrList(20);
	LinkList<int> linkList;
	dLinkList<int> dlinkList;
	ArrStack<int> arrStack(10);
	LinkStack<int> linkStack;
	ArrQueue<int> arrQueue(20);
	LinkQueue<int> linkQueue;

	test_ArrayList(&arrList);
	test_LinkList(&linkList);
	test_LinkList(&dlinkList);
	test_Stack(&arrStack);
	test_Stack(&linkStack);
	test_Queue(&arrQueue);
	test_Queue(&linkQueue);

	system("pause");
	return 0;
}



