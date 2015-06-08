#ifndef queue_h
#define queue_h

template <typename E>
class Queue
{
private:
	struct Link
	{
		Link() : _next(nullptr) {}
		~Link() = default;
		Link(const E& item) : _item(item), _next(nullptr) {}
		Link(const E& item, Link* next) : _item(item), _next(next) {}

		E _item;
		Link* _next;
	};

public:
	Queue() : _size(0) { _head = _tail = new Link(); }
	~Queue() = default;

	bool is_empty() { return _size == 0; }
	void enqueue(const E& item) 
	{
		_tail->_next = new Link(item);
		_tail = _tail->_next;
		_size++;
	}
	E dequeue()
	{
		assert(!is_empty());
		Link* tmp = _head->_next;
		E item = tmp->_item;
		_head->_next = tmp->_next;
		if (_tail->_next == nullptr) _tail = _head;
		free(tmp);
		_size--;
		return item;
	}

private:
	Link* _head;
	Link* _tail;
	int _size;
};

#endif
