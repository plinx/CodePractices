#ifndef _PERSON_H
#define _PERSON_H

#include <string>

struct Person {
	std::string name;
	std::string addr;
	
	std::string getName() const { return name; }
	std::string getAddr() const { return addr; }
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);

#endif