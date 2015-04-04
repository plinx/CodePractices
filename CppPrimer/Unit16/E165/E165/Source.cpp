#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename T>
void print(const T &t)
{
	for (const auto &at : t)
	{
		cout << at << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vi = { 1, 3, 4, 5, 6 };
	vector<string> vl = { "1", "23", "45", "67" };
	list<int> li = { 2, 7, 8, 9, 10 };
	list<string> ls = { "111", "222", "333", "444" };

	print(vi);
	print(vl);
	print(li);
	print(ls);

	return 0;
}