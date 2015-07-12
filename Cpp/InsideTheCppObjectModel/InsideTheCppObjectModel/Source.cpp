#include <cstdio>
#include <cstdlib>
#include "vptr.h"

int main()
{
	nonvptr nv;
	havevptr hv;

	printf("&nonvptr = %p\n", &nv);
	printf("&nonvptr.x = %p\n", &nv.x);
	printf("&nonvptr.y = %p\n", &nv.y);

	printf("&havevptr = %p\n", &hv);
	printf("&havevptr.x = %p\n", &hv.x);
	printf("&havevptr.y = %p\n", &hv.y);

	system("pause");
	return 0;
}