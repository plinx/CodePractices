#ifndef _PERSON_H
#define _PERSON_H

#include <string>
using std::string;

class Person {
	friend std::istream &read(std::istream&, Person&);
	friend std::ostream &print(std::ostream&, Person&);
public:
	Person() = default;
	Person(string n) : name(n), addr("default addr") { }
	Person(string n, string a) : name(n), addr(a) { }
	string getName() const { return name; }
	string getAddr() const { return addr; }

private:
	string name;
	string addr;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, Person&);

#endif