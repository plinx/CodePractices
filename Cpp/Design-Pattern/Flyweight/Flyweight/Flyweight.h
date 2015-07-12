#ifndef Flyweight_h
#define Flyweight_h

class Flyweight
{
public:
	virtual ~Flyweight() = 0;
	virtual int getState() { return state; }
protected:
	Flyweight(int s) : state(s) {}
private:
	int state;
};
Flyweight::~Flyweight() = default;

class ConcreteFlyweight : public Flyweight
{
public:
	ConcreteFlyweight(int s) : Flyweight(s)
	{
		std::cout << "ConcreteFlyweight state : " << getState() << std::endl;
	}
};


#endif