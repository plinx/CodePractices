#ifndef dLinkList_h
#define dLinkList_h

template <typename E>
struct dLinkList : public List<E>
{
private:
	struct Link
	{
		E _item;
		Link* _prev;
		Link* _next;

		Link() : _prev(nullptr), _next(nullptr) {}
		Link(const E& item) 
			: _item(item), _prev(nullptr), _next(nullptr) {}
		Link(const E& item, Link* prev, Link* next) 
			: _item(item), _prev(prev), _next(next) {}

		void* operator new(size_t)
		{
			if (_freeList == nullptr) return ::new Link();
			Link* tmp = _freeList;
			_freeList = _freeList->_next;
			return tmp;
		}

		void operator delete(void* ptr)
		{
			((Link*)ptr)->_next = _freeList;
			_freeList = (Link*)ptr;
		}
	private:
		static Link* _freeList;
	};

private:
	Link* _head;
	Link* _tail;
	Link* _curr;
	int _listSize;

public:
	dLinkList() { _head = _tail = _curr = new Link(); _listSize = 0; }

	void print()
	{
		Link* tmp = _head->_next;
		while (tmp->_next != nullptr)
		{
			std::cout << tmp->_item << ", ";
			tmp = tmp->_next;
		}
		std::cout << tmp->_item << std::endl;
	}

	void clear()
	{
		while (_head != _tail)
		{
			_curr = _head;
			_head = _head->_next;
			delete _curr;
		}
	}

	void insert(const E& item)
	{
		_curr->_next = new Link(item, _curr, _curr->_next);
		_curr->_next->_next->_prev = _curr->_next;
		_curr->_next->_prev = _curr;
		_listSize++;
	}

	void append(const E& item)
	{
		_tail->_next = new Link(item, _tail, nullptr);
		_tail = _tail->_next;
		_listSize++;
	}

	E remove()
	{
		UT_Assert(_curr->_next != nullptr, "No element to remove.");
		Link* tmp = _curr->_next;
		E item = tmp->_item;
		if (_tail == _curr->_next) _tail = _curr;
		_curr->_next = tmp->_next;
		if (_curr->_next != nullptr)
			_curr->_next->_prev = _curr;
		delete tmp;
		_listSize--;

		return item;
	}

	void toBegin() { _curr = _head; }
	void toEnd() { _curr = _tail; }
	void prev() { _curr = _curr->_prev; }
	void next() { _curr = _curr->_next; }
	int length() const { return _listSize; }
	int currPos() const
	{
		Link* tmp = _head;
		int pos;
		for (pos = 0; _curr != tmp; pos++)
			tmp = tmp->_next;
		return pos;
	}

	void toPos(int pos)
	{
		UT_Assert((pos > 0) && (pos < _listSize), "Position out of range.");
		_curr = _head;
		for (int i = 0; i < pos; i++) _curr = _curr->_next;
	}

	const E& getValue() const { return _curr->_item; }

};

template <typename E>
typename dLinkList<E>::Link* dLinkList<E>::Link::_freeList = nullptr;

#endif