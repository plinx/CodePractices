#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::endl;

int main()
{
	int arr[2][6] = {
			{ 1, 3, 5, 7, 9, 11 },
			{ 2, 4, 6, 8, 10, 12 },
	};

	// ver1
	cout << "ver1" << endl;
	for (auto &row : arr) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	// ver2
	cout << "ver2" << endl;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// ver3
	cout << "ver3" << endl;
	for (auto r = begin(arr); r != end(arr); ++r) {
		for (auto c = begin(*r); c != end(*r); ++c) {
			cout << *c << " ";
		}
		cout << endl;
	}

	return 0;
}