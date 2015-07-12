#ifndef Product_h
#define Product_h

enum 
{
	Product_A1 = 0,
	Product_A2,

	Product_B1 = 0,
	Product_B2
};

class ProductA
{
public:
	virtual ~ProductA() = 0;
protected:
	ProductA() = default;
};
ProductA::~ProductA() = default;

class ProductB
{
public:
	virtual ~ProductB() = 0;
protected:
	ProductB() = default;
};
ProductB::~ProductB() = default;

class A1 : public ProductA
{
public:
	A1() { std::cout << "Product : A1" << std::endl; }
};

class A2 : public ProductA
{
public:
	A2() { std::cout << "Product : A2" << std::endl; }
};

class B1 : public ProductB
{
public:
	B1() { std::cout << "Product : B1" << std::endl; }
};

class B2 : public ProductB
{
public:
	B2() { std::cout << "Product : B2" << std::endl; }
};





#endif