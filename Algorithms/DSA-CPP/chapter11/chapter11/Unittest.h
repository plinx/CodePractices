#ifndef Unittest_h
#define Unittest_h

#include <iostream>
#include <string>

inline void UT_Assert(bool condition, std::string output)
{
	if (!condition) std::cout << output << std::endl;
}

#endif