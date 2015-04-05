#include <iostream>
#include "Proxy.h"

int main()
{
	Subject* subject = new ConcreteSubject();
	Proxy* proxy = new Proxy(subject);

	proxy->Request();
	return 0;
}