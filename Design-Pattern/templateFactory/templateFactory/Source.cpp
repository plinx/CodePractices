#include <iostream>
#include "Product.h"
#include "Factory.h"

int main()
{
	Factory* tfactory = new concreteFactory<Tshirt>();
	Product* tproduct = tfactory->createProduct();

	return 0;
}
