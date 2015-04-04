#include <iostream>

int main()
{
	const int i = 42;	// i - const int
	auto j = i;			// j - int
	const auto &k = i;	// k - const int refer
	auto *p = &i;		// p - int *
	const auto j2 = i, &k2 = i;		// j2 - const int, k2 - const int refer

	std::cout << "i : " << i << " j : " << j << std::endl
		<< "k : " << k << " *p : " << *p << std::endl
		<< "j2 : " << j2 << " k2 : " << k2 << std::endl;

	//i = 43;	// i - const int
	j = 43;
	//k = 43;	// k - const int refer
	int tmp = 43;
	p = &tmp;	// p - int *
	//j2 = 43;	// j2 - const int 
	//k2 = 43;	// k2 - const int

	std::cout << "i : " << i << " j : " << j << std::endl
		<< "k : " << k << " *p : " << *p << std::endl
		<< "j2 : " << j2 << " k2 : " << k2 << std::endl;

	return 0;
}