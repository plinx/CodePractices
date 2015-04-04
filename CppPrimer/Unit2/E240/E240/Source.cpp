#include <iostream>
#include <string>

struct Sales_data {
	std::string BookId;
	std::string BookName;
	int totalPrice;
	int Sold;
	float AvgPrice;
};

int main()
{
	Sales_data book1;
	std::cout << "Enter BookId BookName BookPrice Sold:" << std::endl;
	std::cin >> book1.BookId >> book1.BookName >> book1.totalPrice >> book1.Sold;
	book1.AvgPrice = float(book1.totalPrice) / float(book1.Sold);

	std::cout << book1.BookName << " average prices is " << book1.AvgPrice;

	return 0;
}