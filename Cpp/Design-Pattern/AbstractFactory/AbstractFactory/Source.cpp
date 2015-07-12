#include <iostream>
#include "Product.h"
#include "Factory.h"

int main()
{
	Factory* factory = new AbstractFactory();
	ProductA* pa1 = factory->createProductA(Product_A1);
	ProductA* pa2 = factory->createProductA(Product_A2);
	ProductB* pb1 = factory->createProductB(Product_B1);
	ProductB* pb2 = factory->createProductB(Product_B2);
	return 0;
}