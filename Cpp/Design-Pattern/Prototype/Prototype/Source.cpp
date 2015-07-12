#include <iostream>
#include "Prototype.h"

int main()
{
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->clone();
	return 0;
}