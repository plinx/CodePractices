#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data book1, book2;

	std::cout << "Enter book1 ID Name TotalPrice SoldNum :" << std::endl;
	std::cin >> book1.BookId >> book1.BookName >> book1.TotalPrice >> book1.SoldNum;

	std::cout << "Enter book2 ID Name TotalPrice SoldNum :" << std::endl;
	std::cin >> book2.BookId >> book2.BookName >> book2.TotalPrice >> book2.SoldNum;

	if (book1.BookId == book2.BookId) {
		book1.TotalPrice += book2.TotalPrice;
		book1.SoldNum += book2.SoldNum;
		book1.AvgPrice = book1.TotalPrice / book1.SoldNum;

		std::cout << "Book " << book1.BookName << " average price is " << book1.AvgPrice;
	} else {
		book1.AvgPrice = book1.TotalPrice / book1.SoldNum;
		book2.AvgPrice = book2.TotalPrice / book2.SoldNum;
		std::cout << "Book1 " << book1.BookName << " average price is " << book1.AvgPrice << std::endl;
		std::cout << "Book2 " << book2.BookName << " average price is " << book2.AvgPrice << std::endl;
	}


	return 0;
}