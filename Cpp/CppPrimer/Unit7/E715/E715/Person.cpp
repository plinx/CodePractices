#include "Person.h"

Person::Person(std::istream &i)
{
	read(i, *this);
}

std::istream &read(std::istream &i, Person &person)
{
	i >> person.name >> person.addr;
	return i;
}

std::ostream &print(std::ostream &o, Person &person)
{
	o << person.name << " " << person.addr << std::endl;
	return o;
}