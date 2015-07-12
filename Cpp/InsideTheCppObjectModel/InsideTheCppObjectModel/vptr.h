#ifndef vptr_h
#define vptr_h

class nonvptr
{
public:
	float x, y, z;
};

class havevptr
{
public:
	virtual void foo() {}
	float x, y, z;
};

#endif
