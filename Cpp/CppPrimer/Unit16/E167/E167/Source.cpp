#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, unsigned N>
unsigned Size(const T(&)[N])
{
	return N;
}

int main()
{
	int arr[] = { 1, 2, 1, 1, 3, 4, 5, 1 };
	string str[] = { "test string" };
	char c[] =  "test char";
	vector<string> vs[] = { { "1" }, { "2" } };

	cout << "arr[] size : " << Size(arr) << endl;
	cout << "str size : " << Size(str) << endl;
	cout << "c size : " << Size(c) << endl;
	cout << "vs size : " << Size(vs) << endl;

}