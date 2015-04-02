//#include <iostream>
#include <cstdio>

int main(void)
{
	double a, b;
	char s;

	scanf("%lf %c %lf", &a, &s, &b);
	switch (s)
	{
	case '+':
		printf("%.0lf", a + b);
		break;
	case '-':
		printf("%.0lf", a - b);
		break;
	default:
		printf("%.0lf", a * b);
		break;
	}

	return 0;
}