#ifndef Implement_h
#define Implement_h

class Implement
{
public:
	virtual ~Implement() = 0;
	virtual void Operation() = 0;
protected:
	Implement() = default;
};
Implement::~Implement() = default;

class ConcreteImplement : public Implement
{
public:
	ConcreteImplement() { std::cout << "ConcreteImplement constructor." << std::endl; }
	void Operation() { std::cout << "ConcreteImplement Operation()." << std::endl; }
};

#endif