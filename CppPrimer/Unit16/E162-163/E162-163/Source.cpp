#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sales_data
{
	int data;
};

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (less<T>()(v1, v2)) return -1;
	if (less<T>()(v2, v1)) return 1;
	return 0;
}

int main()
{
	vector<int> vi1{ 12 }, vi2{ 10 };
	vector<string> vs1{ "test" }, vs2{ "newtest" };
	Sales_data sd1, sd2;

	cout << "compare(1, 2) : " << compare(1, 2) << endl;
	cout << "compare(vi1, vi2) : " << compare(vi1, vi2) << endl;
	cout << "compare(vs1, vs2) : " << compare(vs1, vs2) << endl;
	//cout << "compare(sd1, sd2) : " << compare(sd1, sd2) << endl;
	//see declaration of 'std::operator <'

	return 0;
}