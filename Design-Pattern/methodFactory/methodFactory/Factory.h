#ifndef Factory_h
#define Factory_h

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* createProduct(int select) = 0;
protected:
	Factory() = default;
};
Factory::~Factory() {}

class concreteFactory : public Factory
{
public:
	concreteFactory() { std::cout << "concreteFactory ..." << std::endl; }
	Product* createProduct(int select)
	{
		switch (select)
		{
		case Product_Tshirt:
			return new Tshirt();
		case Product_Shoes:
			return new Shoes();
		default:
			return new Tshirt();
		}
	}
};

#endif