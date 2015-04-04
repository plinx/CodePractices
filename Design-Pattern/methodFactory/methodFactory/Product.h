#ifndef Product_h
#define Product_h

enum 
{
	Product_Tshirt,
	Product_Shoes
};

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
	Tshirt() { std::cout << "Product : Tshirt" << std::endl; }
};

class Shoes : public Product
{
public:
	Shoes() { std::cout << "Product : Shoes" << std::endl; }
};

#endif