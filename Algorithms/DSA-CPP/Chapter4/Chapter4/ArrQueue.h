#ifndef ArrQueue_h
#define ArrQueue_h

template <typename E>
struct ArrQueue : Queue<E>
{
private:
	int _front;
	int _end;
	int _maxSize;
	E* _listArray;
	
public:
	ArrQueue(int size = defaultSize) 
		: _front(1), _end(0), _maxSize(size + 1) { _listArray = new E[_maxSize]; }
	~ArrQueue() { delete[] _listArray; }

	void clear() { _end = 0; _front = 1; }
	void enqueue(const E& item) 
	{
		UT_Assert(((_end + 2) % _maxSize) != _front, "Queue is full.");
		_end = (_end + 1) % _maxSize;
		_listArray[_end] = item;
	}
	E dequeue()
	{
		UT_Assert(length() != 0, "Queue is empty.");
		E item = _listArray[_front];
		_front = (_front + 1) % _maxSize;
		return item;
	}
	const E& front() const
	{
		UT_Assert(length() != 0, "Queue is empty.");
		return _listArray[_front];
	}
	int length() const { return ((_end + _maxSize) - _front + 1) % _maxSize; }
};

#endif
