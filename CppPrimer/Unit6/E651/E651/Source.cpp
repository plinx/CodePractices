#include <iostream>

using std::cout;
using std::endl;

void f();
void f(int);
void f(int, int);
void f(double, double);

int main()
{
	cout << "f() =>";
	f();
	//cout << "f(2.56, 42) =>";
	//f(2.56, 42);	err: 2 overloads have similar conversions
	cout << "f(42) =>";
	f(42);
	cout << "f(42, 0) =>";
	f(42, 0);
	cout << "f(2.56, 3.14)";
	f(2.56, 3.14);

	return 0;
}

void f()
{
	cout << "func f()" << endl;
}

void f(int)
{
	cout << "func f(int)" << endl;
}

void f(int, int)
{
	cout << "func f(int, int)" << endl;
}

void f(double, double)
{
	cout << "func f(double, double)" << endl;
}
