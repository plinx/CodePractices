#include <iostream>
#include "Singleton.h"

int main()
{
	Singleton singleton1 = Singleton::createSingleton();
	Singleton singleton2 = Singleton::createSingleton();
	return 0;
}