#include "Person.h"

std::istream &read(std::istream &i, Person &person)
{
	i >> person.name >> person.addr;
	return i;
}

std::ostream &print(std::ostream &o, const Person &person)
{
	o << person.name << " " << person.addr << std::endl;
	return o;
}