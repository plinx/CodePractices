#include <memory>
#include <stdio.h>

#include "heap.h"
#include "UnitTest.h"

int main()
{
	e622(); e625();
	test_build_heap();
	e631();
	test_heap_sort();
	e641();
	
	system("pause");
	return 0;
}