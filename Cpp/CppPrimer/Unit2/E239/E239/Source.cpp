#include <iostream>

struct Foo {}	
// without ';' would raise error :
// 'Foo' followed by 'int' is illegal
// return type of 'main' should be 'int' instead of 'Foo'
// 'return':cannot convert from 'int' to 'Foo'

int main()
{
	return 0;
}