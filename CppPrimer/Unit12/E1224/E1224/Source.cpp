#include <iostream>
#include <string>

int main()
{
	char *ch;
	std::string str;
	int i = 0;

	std::cin >> str;
	ch = new char[str.size() + 1];
	for (auto &s : str)
	{
		ch[i] = s;
		++i;
	}
	ch[i] = '\0';

	std::cout << ch << std::endl;
	delete[] ch;

	return 0;
}