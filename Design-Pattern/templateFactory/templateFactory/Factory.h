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

template <typename T>
class concreteFactory : public Factory
{
public:
	concreteFactory() { std::cout << "concreteFactory ..." << std::endl; }
	Product* createProduct() { return new T(); }
};

#endif