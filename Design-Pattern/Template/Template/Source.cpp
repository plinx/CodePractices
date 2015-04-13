#include <iostream>
#include "Template.h"

int main()
{
	TemplateClass* c1 = new ConcreteClass1();
	TemplateClass* c2 = new ConcreteClass2();

	c1->TemplateMethod();
	c2->TemplateMethod();

	return 0;
}