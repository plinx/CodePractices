#ifndef _PERSON_H
#define _PERSON_H

#include <string>
using std::string;

struct Person {
	Person() = default;
	Person(std::istream&);
	Person(string n) : name(n), addr("NoAddr") { }
	Person(string n, string a) : name(n), addr(a) { }

	string getName() const { return name; }
	string getAddr() const { return addr; }

	string name;
	string addr;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, Person&);

#endif