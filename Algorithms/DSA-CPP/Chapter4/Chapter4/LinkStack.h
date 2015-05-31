#ifndef LinkStack_h
#define LinkStack_h

template <typename E>
struct LinkStack : public Stack<E>
{
private:
	enum { defaultSize = 10, };

	struct Link
	{
		E _item;
		Link* _next;

		Link() : _next(nullptr) {}
		Link(const E& item) : _item(item), _next(nullptr) {}
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
			_freeList = nullptr;
		}
	private:
		static Link* _freeList;
	};
private:
	Link* _top;
	int _size;

public:
	LinkStack() : _top(nullptr), _size(0) {}
	~LinkStack() { clear(); }

	void clear()
	{
		while (_top != nullptr)
		{
			Link* tmp = _top;
			_top = _top->_next;
			delete tmp;
		}
		_size = 0;
	}

	void push(const E& item)
	{
		_top = new Link(item, _top);
		_size++;
	}

	E pop()
	{
		UT_Assert(_top != nullptr, "Stack is empty.");
		E item = _top->_item;
		Link* tmp = _top->_next;
		delete _top;
		_top = tmp;
		_size--;
		return item;
	}

	const E& top() const
	{
		UT_Assert(_top != nullptr, "Stack is empty.");
		return _top->_item;
	}
	int length() const { return _size; }
	
};

template <typename E>
typename LinkStack<E>::Link* LinkStack<E>::Link::_freeList = nullptr;

#endif