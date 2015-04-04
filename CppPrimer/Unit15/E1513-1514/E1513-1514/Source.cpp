#include <iostream>
#include <string>

#include "Header.h"

using std::cout;

int main()
{
	base bobj(std::string("test string"));
	base *bp1 = &bobj;
	base &br1 = bobj;
	derived dobj(1);
	base *bp2 = &dobj;
	base &br2 = dobj;

	bobj.print(cout);	// base::print
	dobj.print(cout);	// derived::print
	std::cout << "bp1->name()" << bp1->name() << std::endl;		// base.basename
	std::cout << "bp2->name()" << bp2->name() << std::endl;		// derived.basename
	br1.print(cout);	// base::print
	br2.print(cout);	// derived::print

	return 0;
}