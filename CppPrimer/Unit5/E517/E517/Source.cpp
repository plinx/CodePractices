#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> arr1 = { 1, 2, 3, 4 };
	vector<int> arr2 = { 1, 2, 4};
	int eflag = 1;

	for (int i = 0; i < (arr1.size() < arr2.size() ? arr1.size() : arr2.size()); ++i) {
		if (arr1[i] != arr2[i]) {
			cout << "no subarray in arr1 or arr2" << endl;
			eflag = 0;
		}
	}
	if (eflag) cout << "there is a subarray in arr1 or arr2" << endl;

	return 0;
}