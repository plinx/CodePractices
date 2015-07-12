#include <iostream>
#include "Product.h"
#include "Fatory.h"

int main()
{
	Factory* factory = new concreteFactory();
	Product* product = factory->createProduct();
	return 0;
}