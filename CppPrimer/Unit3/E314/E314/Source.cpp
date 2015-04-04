#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int main()
{
	vector<int> arr;
	int i;
	while (cin >> i) {
		arr.push_back(i);
	}

	cout << "arr : ";
	for (auto t : arr) {
		cout << " " << t << " ";
	}
	cout << std::endl;

	return 0;
}