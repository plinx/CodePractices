#include <iostream>
#include <string>

using namespace std;

template <typename T, unsigned N>
T mbegin(const T(&arr)[N])
{
	return arr[0];
}

template <typename T, unsigned N>
T mend(const T(&arr)[N])
{
	return arr[N - 1];
}

int main()
{
	int ia[] = { 1, 2, 3, 4, 5 };
	char str[] = "test string";

	cout << "ia[] begin : " << mbegin(ia) << endl;
	cout << "ia[] end : " << mend(ia) << endl;

	cout << "str[] begin : " << mbegin(str) << endl;
	cout << "str[] end : " << mend(str) << endl;

	return 0;
}