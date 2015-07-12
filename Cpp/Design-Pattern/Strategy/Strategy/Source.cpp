#include <iostream>
#include <memory>
#include "Strategy.h"
#include "Context.h"

int main()
{
	std::shared_ptr<Strategy> strategy(new ConcreteStrategy1());
	std::shared_ptr<Context> context(new Context(strategy));
	context->DoAction();
	strategy.reset(new ConcreteStrategy2());
	context.reset(new Context(strategy));
	context->DoAction();

	return 0;
}