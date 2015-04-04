#ifndef Prototype_h
#define Prototype_h

class Prototype
{
public:
	virtual ~Prototype() = 0;
	virtual Prototype* clone() const = 0;
protected:
	Prototype() = default;
};
Prototype::~Prototype() = default;

class ConcretePrototype : public Prototype
{
public:
	ConcretePrototype()
	{
		std::cout << "ConcretePrototype ..." << std::endl;
	}
	ConcretePrototype(const ConcretePrototype& cp) : data(cp.data)
	{
		std::cout << "copy assignment ConcretePrototype ..." << std::endl;
	}
	Prototype* clone() const
	{
		return new ConcretePrototype(*this);
	}

private:
	int data;
};

#endif