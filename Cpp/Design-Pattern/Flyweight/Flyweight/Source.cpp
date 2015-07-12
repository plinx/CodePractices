#include <iostream>
#include <vector>

#include "Flyweight.h"
#include "FlyweightFactory.h"

int main()
{
	FlyweightFactory* factory = new FlyweightFactory();
	Flyweight* fly1 = factory->getFlyweight(1);
	Flyweight* fly2 = factory->getFlyweight(3);
	Flyweight* fly3 = factory->getFlyweight(3);

	return 0;
}