#ifndef UnitTest_h
#define UnitTest_h

#include <iostream>
#include <string>

inline void UT_Assert(bool condition, std::string output)
{
	if (!condition)
		std::cout << output << std::endl;
}

#endif