#ifndef Stack_h
#define Stack_h

template <typename E>
struct Stack
{
	Stack() = default;
	virtual ~Stack() = default;

	virtual void clear() = 0;
	virtual void push(const E& item) = 0;
	virtual E pop() = 0;
	virtual const E& top() const = 0;
	virtual int length() const = 0;
};

#endif