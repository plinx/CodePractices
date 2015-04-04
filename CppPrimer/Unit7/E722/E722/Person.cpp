#include "Person.h"

std::istream &read(std::istream &i, Person &person)
{
	i >> person.name >> person.addr;
	return i;
}

std::ostream &print(std::ostream &o, Person &person)
{
	o << person.getName() << person.getAddr() << std::endl;
	return o;
}