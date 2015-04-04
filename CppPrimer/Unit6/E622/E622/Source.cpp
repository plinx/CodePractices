#include <iostream>

void chval(int *, int *);

int main()
{
	int i1, i2;
	int *p1 = &i1, *p2 = &i2;

	std::cin >> i1 >> i2;

	std::cout << "i1 : " << i1 << " i2 :" << i2 << std::endl;
	chval(p1, p2);
	std::cout << "i1 : " << i1 << " i2 :" << i2 << std::endl;

	return 0;
}

void chval(int *p1, int *p2)
{
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}