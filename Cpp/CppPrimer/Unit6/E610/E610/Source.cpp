#include <iostream>

void func(int *p1, int *p2);

int main()
{
	int x, y;
	int *px, *py;
	px = &x;
	py = &y;

	std::cin >> x >> y;

	std::cout << x << " " << y << std::endl;
	func(px, py);
	std::cout << x << " " << y << std::endl;

}

void func(int *p1, int *p2)
{
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}