#ifndef Strategy_h
#define Strategy_h

class Strategy
{
public:
	Strategy() = default;
	virtual ~Strategy() = default;
	virtual void AlgInterface() = 0;
};

class ConcreteStrategy1 : public Strategy
{
public:
	ConcreteStrategy1() = default;
	void AlgInterface() { std::cout << "ConcreteStrategy1 AlgInterface ..." << std::endl; }
};

class ConcreteStrategy2 : public Strategy
{
public:
	ConcreteStrategy2() = default;
	void AlgInterface() { std::cout << "ConcreteStrategy2 AlgInterface ..." << std::endl; }
};

#endif
