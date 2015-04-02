#include <iostream>
#include <time.h>
#include "Vector.h"

using namespace std;

int main()
{
	double t1s, t1e, t2s, t2e;
	int ia[] = { 1, 3, 2, 5, 4, 6 };
	Vector<int> vint1(ia, 6);
	Vector<int> vint2(ia, 6);

	t1s = (double)clock();
	vint1.bubbleSort(0, vint1.Size);
	t1e = (double)clock();
	t2s = (double)clock();
	vint2.mergeSort(0, vint2.Size);
	t2e = (double)clock();

	cout << "bubble sort time : " << t1e - t1s << endl;
	cout << "merge sort time : " << t2e - t2s << endl;

	return 0;
}