#ifndef Factory_h
#define Factory_h

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual ProductA* createProductA(int select) = 0;
	virtual ProductB* createProductB(int select) = 0;
protected:
	Factory() = default;
};
Factory::~Factory() = default;

class AbstractFactory : public Factory
{
public:
	AbstractFactory() { std::cout << "AbstractFactory created." << std::endl; }
	ProductA* createProductA(int select) 
	{ 
		switch (select)
		{
		case Product_A1:
			return new A1();
		case Product_A2:
			return new A2();
		default:
			return nullptr;
		}
	}
	ProductB* createProductB(int select)
	{
		switch (select)
		{
		case Product_B1:
			return new B1();
		case Product_B2:
			return new B2();
		default:
			return nullptr;
		}
	}
};

#endif