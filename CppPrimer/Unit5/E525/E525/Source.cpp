#include <iostream>
#include <exception>

int main()
{
	int val1, val2;
	int lflag = 0;
	char ch;

	do {
		try {
			lflag = 0;
			std::cin >> val1 >> val2;
			if (val2 == 0) throw std::runtime_error("val2 is 0");
		} catch (std::runtime_error) {
			std::cout << "err value '0', enter again? (y/n) :";
			std::cin >> ch;
			if (ch == 'y' || ch == 'Y')
				lflag = 1;
		}
	} while (lflag);
	
	std::cout << val1 / val2 << std::endl;

	return 0;
}