#ifndef ArrList_h
#define ArrList_h

template <typename E>
class ArrList : public List<E>
{
	enum { defaultSize = 10, };
private:
	int _maxSize;
	int _listSize;
	int _curr;
	E* _listArray;

public:
	ArrList(int maxSize = defaultSize) 
		: _maxSize(maxSize), _listSize(0), _listArray(0)
	{
		_listArray = new E[_maxSize];
	}
	~ArrList() { delete[] _listArray; }

	void print()
	{
		for (int i = 0; i < _listSize - 1; i++)
			std::cout << _listArray[i] << ", ";
		std::cout << _listArray[_listSize - 1] << std::endl;
	}
	void clear() 
	{
		delete[] _listArray;
		_listSize = _curr = 0;
		_listArray = new E[_maxSize];
	}

	void insert(const E& item) 
	{
		UT_Assert(_listSize < _maxSize, "List capacity exceeded.");
		for (int i = _listSize; i > _curr; i--)
			_listArray[i] = _listArray[i - 1];
		_listArray[_curr] = item;
		_listSize++;
	}

	void append(const E& item) 
	{
		UT_Assert(_listSize < _maxSize, "List capacity exceeded.");
		_listArray[_listSize++] = item;
	}

	E remove()
	{
		UT_Assert((_curr >= 0) && (_curr < _listSize), "No element.");
		E item = _listArray[_curr];
		for (int i = _curr; i < _listSize; i++)
			_listArray[i] = _listArray[i + 1];
		_listSize--;
		return item;
	}

	void toBegin() { _curr = 0; }
	void toEnd() { _curr = _listSize - 1; }
	void prev() { if (_curr != 0) _curr--; }
	void next() { if (_curr != _listSize) _curr++; }
	int length() const { return _listSize; }
	int currPos() const { return _curr; }

	void toPos(int pos)
	{
		UT_Assert((pos >= 0) && (pos < _listSize), "Position out of range.");
		_curr = pos;
	}

	const E& getValue() const
	{
		UT_Assert((_curr >= 0) && (_curr < _listSize), "No _current element.");
		return _listArray[_curr];
	}

};

#endif