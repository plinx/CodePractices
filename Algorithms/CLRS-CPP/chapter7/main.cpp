#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <random>

#include "qsort.h"
#include "UnitTest.h"

int main()
{
	srand((unsigned)time(NULL));
	test_quicksort();
	e711(); e712(); e714();
	test_quicksort_random();

	system("pause");
	return 0;
}