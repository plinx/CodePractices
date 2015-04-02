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

	cout << "v1 size :" << v1.size() << endl;
	cout << "v1 var :";
	for (auto i : v1) {
		cout << i;
	}
	cout << endl;

	cout << "v2 size :" << v2.size() << endl;
	cout << "v2 var :";
	for (auto i : v2) {
		cout << i;
	}
	cout << endl;

	cout << "v3 size :" << v3.size() << endl;
	cout << "v3 var :";
	for (auto i : v3) {
		cout << i;
	}
	cout << endl;

	cout << "v4 size :" << v4.size() << endl;
	cout << "v4 var :";
	for (auto i : v4) {
		cout << i;
	}
	cout << endl;

	cout << "v5 size :" << v5.size() << endl;
	cout << "v5 var :";
	for (auto i : v5) {
		cout << i;
	}
	cout << endl;

	cout << "v6 size :" << v6.size() << endl;
	cout << "v6 var :";
	for (auto s : v6) {
		cout << s;
	}
	cout << endl;

	cout << "v7 size :" << v7.size() << endl;
	cout << "v7 var :";
	for (auto s : v7) {
		cout << s;
	}
	cout << endl;

	return 0;


}
