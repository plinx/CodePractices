#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
	char ch1[] = "hello, ";
	char ch2[] = "world.";
	char newch[14] = "";

	strcpy_s(newch, ch1);
	strcat_s(newch, ch2);

	cout << newch << endl;

	return 0;
}