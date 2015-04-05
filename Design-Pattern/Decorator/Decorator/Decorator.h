#ifndef Decorator_h
#define Decorator_h

class Component
{
public:
	virtual ~Component() = 0;
	virtual void Operation() = 0;
protected:
	Component() = default;
};
Component::~Component() = default;

class ConcreteComponent : public Component
{
public:
	ConcreteComponent() = default;
	void Operation() { std::cout << "ConcreteComponent operation ..." << std::endl; }
};

class Decorator : public Component
{
public:
	Decorator(Component* c) : com(c) {}
	virtual void Operation() {}
protected:
	Component* com;
};

class ConcreteDecorator : public Decorator
{
public:
	ConcreteDecorator(Component* c) : Decorator(c) {}
	void Operation() { com->Operation(); this->AdditionOperation(); }
	void AdditionOperation() { std::cout << "ConcreteDecorator AdditionOperation." << std::endl; }
};

#endif