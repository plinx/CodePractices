#include <iostream>
#include "Product.h"
#include "Factory.h"

int main()
{
	Factory* factory = new concreteFactory();
	Product* tshirt = factory->createProduct(Product_Tshirt);
	Product* shoes = factory->createProduct(Product_Shoes);

	return 0; 
}