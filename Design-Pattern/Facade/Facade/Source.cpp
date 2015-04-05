#include <iostream>
#include "Facade.h"

int main()
{
	Facade* facade = new Facade();
	facade->OperationWrapper();

	return 0;
}