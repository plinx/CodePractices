#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 0, 1, 2 };
	
	auto zero = find(lst.crbegin(), lst.crend(), 0);

	while (zero.base() != lst.cend())
	{
		cout << *zero << " ";
		--zero;
	}
	cout << *zero;
	cout << endl;

	return 0;
}