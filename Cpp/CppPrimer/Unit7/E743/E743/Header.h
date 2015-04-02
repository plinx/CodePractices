#ifndef HEADER_H
#define HEADER_H
#include <iostream>

class NoDefault {
public:
	NoDefault() = default;
	NoDefault(int i) : dint(i) {}
	int rval() { return dint; }
private:
	int dint;
};

class C {
public:
	C(int i) : noDefault(i) {}
	C() : C(0) {}
	void print() { std::cout << "noDefault in C :" << noDefault.rval() << std::endl; }
private:
	NoDefault noDefault;
};

#endif