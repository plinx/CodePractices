#include <iostream>
#include <stdio.h>

int main()
{
	int a[3][4] = { 
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11 
	};

	std::cout << *(&a[0][0] + 5) << ", " << *(*(a + 1) + 1) << ", ";
	std::cout << *(&a[1] + 1) << ", " << *(a + 5) << std::endl;
	std::cout << "fixed :" << std::endl;
	std::cout << *(&a[0][0] + 5) << ", " << *(*(a + 1) + 1) << ", ";
	std::cout << *(*(&a[1]) + 1) << ", " << *(*a + 5) << std::endl;

	std::cout << a << " " << *a << " " << &a << " " << &a[0] << std::endl;
	std::cout << a + 1 << " " << *a + 1 << " " << &a + 1 << " " << &a[0] + 1 << std::endl;
	std::cout << *(a + 1) << " " << *(*a + 1) << " " << *(&a + 1) << " " << *(&a[0] + 1) << std::endl;

	system("pause");
	return 0;
}