#ifndef TestCase_h
#define TestCase_h

template <typename E>
void test_ArrayList(List<E>* list);
template <typename E>
void test_LinkList(List<E>* list);
template <typename E>
void test_Stack(Stack<E>* stack);

// implement
template <typename E>
void test_ArrayList(List<E>* list)
{
	for (int i = 0; i < 10; i++)
		list->append(i * 2);

	//list->print();
	list->toEnd();
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
	list->clear();
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

template <typename E>
void test_Stack(Stack<E>* stack)
{
	for (int i = 0; i < 6; i++)
		stack->push(i * 2);

	UT_Assert(stack->top() == 10, "Stack push error.");
	stack->push(5);
	UT_Assert(stack->length() == 7, "Stack length error.");
	UT_Assert(stack->pop() == 5, "Stack pop error.");
	stack->clear();
	stack->push(1);
	UT_Assert(stack->top() == 1, "Stack clear error.");

}


#endif