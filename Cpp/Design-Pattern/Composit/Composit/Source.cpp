#include <iostream>
#include <vector>
#include "Component.h"
#include "Composite.h"

int main()
{
	Component* leaf1 = new Leaf();
	Component* leaf2 = new Leaf();
	Component* composite = new Composite();
	
	composite->Add(leaf1);
	composite->Add(leaf2);
	composite->Operation();
	composite->Remove(leaf1);
	composite->Operation();
	composite->getChild(1)->Operation();
	composite->getChild(0)->Operation();
	

	return 0;
}