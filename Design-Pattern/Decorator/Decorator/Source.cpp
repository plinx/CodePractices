#include <iostream>
#include "Decorator.h"

int main()
{
	Component* com = new ConcreteComponent();
	Decorator* dec = new ConcreteDecorator(com);

	dec->Operation();

	return 0;
}