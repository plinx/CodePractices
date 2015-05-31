#include "stdafx.h"

template <typename E>
void test_ArrayList(List<E>* list);
template <typename E>
void test_LinkList(List<E>* list);

int main()
{
	ArrList<int> arrList(20);
	LinkList<int> linkList;
	dLinkList<int> dlinkList;
	test_ArrayList(&arrList);
	test_LinkList(&linkList);
	test_LinkList(&dlinkList);

	system("pause");
	return 0;
}

template <typename E>
void test_ArrayList(List<E>* list)
{
	for (int i = 0; i < 10; i++)
		list->append(i * 2);

	//list->print();
	/*list->toEnd();
	UT_Assert(list->getValue() == 18, "List toEnd error.");
	list->toBegin();
	list->insert(26);
	//list->print();
	UT_Assert(list->getValue() == 26, "ArrList insert error.");
	list->toPos(5);
	UT_Assert(list->getValue() == 8, "ArrList toPos error.");
	list->toEnd();
	UT_Assert(list->remove() == 18, "ArrList remove error.");
	//list->print();
	UT_Assert(list->currPos() == 10, "ArrList currPos error.");
	list->toEnd();
	UT_Assert(list->getValue() == 16, "ArrList remove error.");
	list->clear();*/
}

template <typename E>
void test_LinkList(List<E>* list)
{
	for (int i = 0; i < 10; i++)
		list->append(i * 2);

	//list->print();
	list->toEnd();
	UT_Assert(list->getValue() == 18, "List toEnd error.");
	list->toBegin();
	list->insert(26);
	list->next();
	//list->print();
	UT_Assert(list->getValue() == 26, "ArrList insert error.");
	list->toPos(5);
	UT_Assert(list->getValue() == 6, "ArrList toPos error.");
	list->toEnd();
	list->prev();
	UT_Assert(list->remove() == 18, "ArrList remove error.");
	//list->print();
	UT_Assert(list->currPos() == 10, "ArrList currPos error.");
	list->toEnd();
	UT_Assert(list->getValue() == 16, "ArrList toEnd error.");
	list->clear();
}

