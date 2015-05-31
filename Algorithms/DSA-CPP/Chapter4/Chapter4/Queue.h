#ifndef Queue_h
#define Queue_h

template <typename E>
struct Queue
{
	Queue() = default;
	virtual ~Queue() = default;

	virtual void clear() = 0;
	virtual void enqueue(const E& item) = 0;
	virtual E dequeue() = 0;
	virtual const E& front() const = 0;
	virtual int length() const = 0;
};

#endif

