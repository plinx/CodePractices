#ifndef UnitTest_h
#define UnitTest_h

#include <assert.h>
#include <string>
#include "dp.h"

void test_cur_rod()
{
	vector<int> table = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	cout << cur_rod(table, 10) << " ";
	cout << memoized_cur_rod(table, 10) << " ";
	cout << bottom_up_cur_rod(table, 10) << endl;
}

void test_all()
{
	test_cur_rod();
}

#endif