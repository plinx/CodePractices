#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item itemsum, item;
	std::cin >> item;
	itemsum = item;
	while (std::cin >> item) {
		if (item.isbn() == itemsum.isbn()) {
			itemsum += item;
		} else {
			break;
		}
	}
	std::cout << itemsum << std::endl;

	return 0;
}