#include "stdafx.h"

class A
{
	int a;
public:
	void virtual f() { printf("A\n"); }
};

class B : public A
{
	char b[3];
public:
	void virtual fb() { printf("B\n"); }
};

int matoi(const char *p)
{
	int res = 0;
	bool flag = false;
	while (' ' == *p || '\t' == *p) p++;
	if ('+' == *p || '-' == *p)
		flag = ('+' == *p++);
	while (*p)
		res = res * 10 + (*p++ - '0');

	return flag ? res : -res;
}

class C : public virtual B
{
	char c[3];
public:
	void virtual fc() {}
};


int main()
{
	//t15();
	char s1[] = " +321";
	char s2[] = " -321";

	printf("%d %d\n", matoi(s1), matoi(s2));
	printf("%d %d %d", sizeof(A), sizeof(B), sizeof(C));


	system("pause");
	return 0;
}
