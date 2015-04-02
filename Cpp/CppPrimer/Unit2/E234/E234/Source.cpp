#include <iostream>

int main()
{
	int i = 0, &r = i;
	auto a = r;		// a - int
	const int ci = i, &cr = ci;
	auto b = ci;	// b - int
	auto c = cr;	// c - int
	auto d = &i;	// d - int *
	auto e = &ci;	// e - const int *
	const auto f = ci;	// f - const int
	auto &g = ci;		// g - const int refer
	//auto &h = 42;	// err
	const auto &j = 42; // j - const int refer

	std::cout << "a : " << a << " b : " << b << std::endl
		<< "c : " << c << " d : " << d << std::endl
		<< "e : " << e << " g : " << g << std::endl;

	a = 42;		// a - int 
	b = 42;		// b - int
	c = 42;		// c - int
	//d = 42;	// err: d - int *
	//e = 42;	// err: e - const int *
	//g = 42;		// err: g - int refer

	std::cout << "a : " << a << " b : " << b << std::endl
		<< "c : " << c << " d : " << d << std::endl
		<< "e : " << e << " g : " << g << std::endl;

	return 0;
	

}