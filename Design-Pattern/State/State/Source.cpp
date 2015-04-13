#include <iostream>
#include <memory>
#include "State.h"

int main()
{
	Machine* machine = new Machine();
	State* state = new State1();
	machine->ChangeState(state);
	machine->Operation();
	machine->Operation();
	state->test();

	delete state;
	delete machine;

	return 0;
}