#include <iostream>

std::istream& get_input(std::istream &);

int main()
{
	get_input(std::cin);
	return 0;
}

std::istream& get_input(std::istream &is)
{
	int i;
	auto old_state = is.rdstate();
	is.clear();
	std::cout << "Please Enter data :" << std::endl;
	while (is >> i)
	{
		std::cout << "Got :" << i << std::endl;
	}
	is.setstate(old_state);
	return is;
}