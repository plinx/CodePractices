#include <iostream>
#include "Adapter.h"

int main()
{
	Adaptee* adaptee = new Adaptee();
	Target* adaptar1 = new Adapter1();
	Target* adapter2 = new Adapter2(adaptee);

	adaptar1->Request();
	adapter2->Request();
	return 0;
}