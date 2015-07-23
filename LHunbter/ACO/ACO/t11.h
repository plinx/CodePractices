#ifndef t11_h
#define t11_h

#include <math.h>

double power(double x, int n)
{
	if (n == 0) 
		return 1;

	int result = 1;
	while (n)
	{
		if ((n & 1) != 0)
			result *= x;

		n >>= 1;
		x *= x;
	}
	return result;
}

void t11()
{
	printf("%f\n", pow(10.0, 5));
	printf("%f\n", pow(-10.0, 2));
	printf("%f\n", pow(-10.0, 3));
	printf("%f\n", power(10.0, 5));
	printf("%f\n", power(-10.0, 2));
	printf("%f\n", power(-10.0, 3));
}

#endif