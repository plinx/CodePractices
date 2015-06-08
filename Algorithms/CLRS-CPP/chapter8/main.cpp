#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <memory>
#include <string>

#include "queue.h"
#include "sorts.h"
#include "UnitTest.h"

int main()
{
	test_count_sort();
	e821(); e823();
	test_radix_sort_int();
	test_radix_sort_str();

	system("pause");
	return 0;
}