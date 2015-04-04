#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto rv = vec.crbegin();

	while (rv != vec.crend())
	{
		cout << *rv << " ";
		++rv;
	}
	cout << endl;

	return 0;
}