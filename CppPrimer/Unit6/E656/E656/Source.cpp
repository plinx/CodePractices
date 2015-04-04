#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int add(int, int);
int del(int, int);
int mul(int, int);
int mod(int, int);

int main()
{
	vector<int(*)(int, int)> pFunc(4);
	pFunc[0] = add;
	pFunc[1] = del;
	pFunc[2] = mul;
	pFunc[3] = mod;

	std::cout << pFunc[0](1, 1) << std::endl;
	std::cout << pFunc[1](1, 1) << std::endl;
	std::cout << pFunc[2](1, 1) << std::endl;
	std::cout << pFunc[3](1, 1) << std::endl;

	return 0;
}

int add(int val1, int val2)
{
	return val1 + val2;
}

int del(int val1, int val2)
{
	return (val1 > val2) ? (val1 - val2) : (val1 < val2);
}

int mul(int val1, int val2)
{
	return val1*val2;
}

int mod(int val1, int val2)
{
	return (val1 > val2) ? (val1 / val2) : (val2 / val1);
}
