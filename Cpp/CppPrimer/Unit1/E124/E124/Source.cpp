#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item itemsum, item;
	if (std::cin >> itemsum) {
		while (std::cin >> item) {
			if (item.isbn() == itemsum.isbn()) {
				itemsum += item;
			} else {
				std::cout << itemsum << std::endl;
				itemsum = item;
			}
		}
		std::cout << itemsum << std::endl;
	}
	return 0;
}