#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	vector<int>::reverse_iterator rit = vec.rbegin();

	while (rit != vec.crend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}