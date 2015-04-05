#ifndef Abstract_h
#define Abstract_h

class Abstract
{
public:
	virtual ~Abstract() = 0;
	virtual void Operation() = 0;
protected:
	Abstract() = default;
};
Abstract::~Abstract() = default;

class ConcreteAbstract : public Abstract
{
public:
	ConcreteAbstract(Implement* i) : imp(i) {}
	void Operation() { imp->Operation(); }
private:
	Implement* imp;
};

#endif