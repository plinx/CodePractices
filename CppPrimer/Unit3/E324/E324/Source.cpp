#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> arr;
	int in, sum = 0;
	while (cin >> in) {
		arr.push_back(in);
	}

	for (auto i = arr.begin(); i != arr.end(); ++i) {
		if (i == arr.end() - 1) {
			cout << "leave " << *i << endl;
			break;
		}
		
		cout << *i << " + " << *(i + 1) << " = " << *i + *(i + 1) << endl;
		++i;
	}

	auto b = arr.begin();
	auto e = arr.end();
	for (auto b = arr.begin(), e = arr.end(); b != e; ++b, --e) {
		if (b == e - 1) {
			cout << "leave " << *b << endl;
			break;
		}
		cout << *b << " + " << *(e-1) << " = " << *b + *(e-1) << endl;

	}

	return 0;
}