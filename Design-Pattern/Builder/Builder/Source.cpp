#include <iostream>
#include "Product.h"
#include "Builder.h"
#include "Director.h"

int main()
{
	Director director;
	Builder* blackBuilder = new BlackBuilder();
	Builder* whiteBuilder = new WhiteBuilder();

	director.setBuilder(blackBuilder);
	director.constructPixel(100, 100);
	director.getPixel()->print();

	director.setBuilder(whiteBuilder);
	director.constructPixel(200, 200);
	director.getPixel()->print();

	return 0;
}