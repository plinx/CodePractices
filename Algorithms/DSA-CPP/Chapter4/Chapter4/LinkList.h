#ifndef LinkList_h
#define LinkList_h

template <typename E>
class LinkList : public List<E>
{
	enum { defaultSize = 10, };
	struct Link
	{
		E _item;
		Link* _next;

		Link() : _next(NULL) {}
		Link(Link* next) : _next(next) {}
		Link(const E& item, Link* next) : _item(item), _next(next) {}

		void* operator new(size_t)
		{
			if (_freeList == NULL) return ::new Link();
			Link* tmp = _freeList;
			_freeList = _freeList->_next;
			return tmp;
		}

		void operator delete(void *ptr)
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

	void init() { _curr = _tail = _head = new Link(); _listSize = 0; }
	void removeAll()
	{
		while (_head != NULL)
		{
			_curr = _head;
			_head = _head->_next;
			delete _curr;
		}
	}
public:
	LinkList() 
	{ 
		init(); 
	}
	~LinkList() { removeAll(); }

	void print()
	{
		Link* tmp = _head->_next;
		while (tmp->_next != NULL)
		{
			std::cout << tmp->_item << ", ";
			tmp = tmp->_next;
		}
		std::cout << tmp->_item << std::endl;
	}

	void clear() { removeAll(); init(); }
	void insert(const E& item)
	{
		_curr->_next = new Link(item, _curr->_next);
		if (_tail == _curr) _tail = _curr->_next;
		_listSize++;
	}
	void append(const E& item) 
	{
		_tail->_next = new Link(item, NULL);
		_tail = _tail->_next;
		_listSize++;
	}
	E remove() 
	{ 
		UT_Assert(_curr->_next != NULL, "No element.");
		E item = _curr->_next->_item;
		Link* tmp = _curr->_next;
		if (_tail == _curr->_next) _tail = _curr;
		_curr->_next = _curr->_next->_next;
		delete tmp;
		_listSize--;

		return item; 
	}
	void toBegin() { _curr = _head; }
	void toEnd() { _curr = _tail; }
	void prev() 
	{ 
		if (_curr == _head) return;
		Link* tmp = _head;
		while (tmp->_next != _curr) tmp = tmp->_next;
		_curr = tmp;
	}
	void next()
	{
		if (_curr != _tail) _curr = _curr->_next;
	}
	int length() const { return _listSize; }
	int currPos() const 
	{ 
		Link* tmp = _head;
		int pos = 0;
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
typename LinkList<E>::Link* LinkList<E>::Link::_freeList = nullptr;

#endif