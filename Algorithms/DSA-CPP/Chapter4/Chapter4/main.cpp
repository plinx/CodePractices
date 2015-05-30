#include "stdafx.h"

int main()
{
	ArrList<int> arrList(20);
	for (int i = 0; i < 10; i++)
		arrList.append(i * 2);

	//arrList.print();
	arrList.toEnd();
	UT_Assert(arrList.getValue() == 18, "List toEnd error.");
	arrList.toBegin();
	arrList.insert(26);
	//arrList.print();
	UT_Assert(arrList.getValue() == 26, "ArrList insert error.");
	arrList.toPos(5);
	UT_Assert(arrList.getValue() == 8, "ArrList toPos error.");
	arrList.toEnd();
	UT_Assert(arrList.remove() == 18, "ArrList remove error.");
	//arrList.print();
	UT_Assert(arrList.currPos() == 10, "ArrList currPos error.");
	arrList.toEnd();
	UT_Assert(arrList.getValue() == 16, "ArrList remove error.");
	arrList.clear();


	LinkList<int> linkList;

	for (int i = 0; i < 10; i++)
		linkList.append(i * 2);

	//linkList.print();
	linkList.toEnd();
	UT_Assert(linkList.getValue() == 18, "LinkList toEnd error.");
	linkList.toBegin();		// to _head, empty position
	linkList.insert(26);
	linkList.next();
	//linkList.print();
	UT_Assert(linkList.getValue() == 26, "LinkList insert error.");
	linkList.toEnd();
	linkList.prev();
	UT_Assert(linkList.remove() == 18, "LinkList remove error.");
	linkList.print();
	UT_Assert(linkList.currPos() == 10, "LinkList currPos error.");
	linkList.toPos(5);
	UT_Assert(linkList.getValue() == 6, "LinkList toPos error.");
	linkList.clear();

	system("pause");
	return 0;
}
