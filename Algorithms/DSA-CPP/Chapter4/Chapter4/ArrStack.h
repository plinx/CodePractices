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
};

#endif