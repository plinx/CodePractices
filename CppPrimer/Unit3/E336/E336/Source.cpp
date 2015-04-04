#include <iostream>
#include <conio.h>
#include <vector>
#include <iterator>

using std::vector;
using std::begin;
using std::end;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int arr1[10] = { 1, 2, 3, 4 };
	int arr2[10] = { 1, 2, 3, 4, 5 };
	vector<int> varr1(10, 1), varr2(10, 1);
	int eflag = 1;


	for (int i = 0; i < 10; ++i) {
		if (arr1[i] != arr2[i]) {
			cout << "arr1 != arr2" << endl;
			eflag = 0;
			break;
		}
	}
	if (eflag)
		cout << "arr1 == arr2" << endl;

	if (varr1 == varr2) {
		cout << "varr1 == varr2" << endl;
	} else {
		cout << "varr1 != varr2" << endl;
	}

	return 0;
}