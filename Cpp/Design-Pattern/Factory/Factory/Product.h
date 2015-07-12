#ifndef Product_h
#define Product_h

class Product 
{
public:
	virtual ~Product() = 0;
protected:
	Product() = default;
};

Product::~Product() {}

class Tshirt : public Product
{
public:
	Tshirt() { std::cout << "Product : Tshirt is created." << std::endl; }
};


#endif