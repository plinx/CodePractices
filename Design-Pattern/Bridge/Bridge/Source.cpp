#include <iostream>
#include "Implement.h"
#include "Abstract.h"

int main()
{
	Implement* imp = new ConcreteImplement();
	Abstract* abs = new ConcreteAbstract(imp);
	abs->Operation();

	return 0;
}