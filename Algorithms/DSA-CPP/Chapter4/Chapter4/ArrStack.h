#ifndef ArrStack_h
#define ArrStack_h

template <typename E>
struct ArrStack : public Stack<E>
{
private:
	int _maxSize;
	int _top;
	E* _listArray;
public:
	ArrStack(int maxSize) : _maxSize(maxSize), _top(0) {
		_listArray = new E[_maxSize];
	}
	~ArrStack() = default;

	void clear() { _top = 0; }
	void push(const E& item) 
	{
		UT_Assert(_top != _maxSize, "Stack is full.");
		_listArray[_top++] = item;
	}
	E pop() 
	{
		UT_Assert(_top != 0, "Stack is empty.");
		return _listArray[--_top];
	}
	const E& top() const
	{
		UT_Assert(_top != 0, "Stack is empty.");
		return _listArray[_top - 1];
	}
	int length() const { return _top; }
};

#endif