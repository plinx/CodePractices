#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };

	cout << "v1 : " << endl;
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "v2 : " << endl;
	for (auto i = v2.begin(); i != v2.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "v3 : " << endl;
	for (auto i = v3.begin(); i != v3.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "v4 : " << endl;
	for (auto i = v4.begin(); i != v4.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "v5 : " << endl;
	for (auto i = v5.begin(); i != v5.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "v6 : " << endl;
	for (auto s = v6.begin(); s != v6.end(); ++s) {
		cout << *s << " ";
	}
	cout << endl;

	cout << "v7 : " << endl;
	for (auto s = v7.begin(); s != v7.end(); ++s) {
		cout << *s << " ";
	}
	cout << endl;

	return 0;
}