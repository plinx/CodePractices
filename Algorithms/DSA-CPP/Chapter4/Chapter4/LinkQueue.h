#ifndef LinkQueue_h
#define LinkQueue_h

template <typename E>
struct LinkQueue : public Queue<E>
{
private:
	enum { defautlSize = 20, };
	struct Link
	{
		E _item;
		Link* _next;

		Link() : _next(nullptr) {}
		Link(const E& item, Link* next) : _item(item), _next(next) {}

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
	Link* _front;
	Link* _end;
	int _size;

public:
	LinkQueue() : _size(0) { _front = _end = new Link(); }
	~LinkQueue() { clear(); delete _front; }

	void clear()
	{
		while (_front->_next != nullptr)
		{
			_end = _front->_next;
			_front->_next = _end->_next;
			delete _end;
		}
		_end = _front;
		_size = 0;
	}

	void enqueue(const E& item)
	{
		_end->_next = new Link(item, nullptr);
		_end = _end->_next;
		_size++;
	}

	E dequeue()
	{
		UT_Assert(_size != 0, "Queue is empty.");
		E item = _front->_next->_item;
		Link* tmp = _front->_next;
		_front->_next = tmp->_next;
		if (_end == tmp) _end = _front;
		delete tmp;
		_size--;
		return item;
	}

	const E& front() const
	{
		UT_Assert(_size != 0, "Queue is empty.");
		return _front->_next->_item;
	}

	int length() const { return _size; }

};

template <typename E>
typename LinkQueue<E>::Link* LinkQueue<E>::Link::_freeList = nullptr;

#endif
