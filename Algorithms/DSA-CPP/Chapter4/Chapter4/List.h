#ifndef List_h
#define List_h

template <typename E>
struct List
{
	List() = default;
	virtual ~List() = default;

	virtual void print() = 0;
	virtual void clear() = 0;
	virtual void insert(const E& item) = 0;
	virtual void append(const E& item) = 0;
	virtual E remove() = 0;
	virtual void toBegin() = 0;
	virtual void toEnd() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int length() const = 0;
	virtual int currPos() const = 0;
	virtual void toPos(int pos) = 0;
	virtual const E& getValue() const = 0;

};

#endif