#include <iostream>

int main(int argc, char *argv[])
{
	int i = 1;

	while (argv[i] != '\0') {
		std::cout << argv[i];
		++i;
	}
}