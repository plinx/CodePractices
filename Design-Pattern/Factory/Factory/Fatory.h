#ifndef Factory_h
#define Factory_h

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* createProduct() = 0;
protected:
	Factory() = default;
};

Factory::~Factory() {}

class concreteFactory : public Factory
{
public:
	Product* createProduct() { return new Tshirt(); }
	concreteFactory() { std::cout << "concreteFactory ..." << std::endl; }
};

#endif