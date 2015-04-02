#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
using std::string;

struct Person
{
	string getName() const { return Name; }
	string getAddr() const { return Addr; }
	string getNum() const { return number; }

	string Name;
	string Addr;
	string number;
};

#endif