#include <iostream>
#include <string>

int main()
{
	char *ch1 = new char[10];
	char *ch2 = new char[10];
	std::string str1;
	std::string str2;

	std::cout << "Enter char1 and char2 : " << std::endl;
	std::cin >> ch1 >> ch2;

	size_t n = strlen(ch1) + strlen(ch2);
//	std::cout << "n = " << strlen(ch1) << " + " << strlen(ch2) << std::endl;
	char *newch = new char[n];

	std::cout << "new char string connect char1 and char2 : " << std::endl;
	for (size_t i = 0; i <= n; ++i)
	{
		if (i <= strlen(ch1))
		{
			newch[i] = ch1[i];
		}
		else
		{
			newch[i] = ch2[i - strlen(ch1) -1];
		}
		std::cout << newch[i];
	}
	delete[] ch1;
	delete[] ch2;
	delete[] newch;
	std::cout << std::endl;

	std::cout << "Enter str1 and str2 : " << std::endl;
	std::cin >> str1 >> str2;

	std::string nstr = str1 + " " + str2;
	std::cout << "new string connect str1 and str2 : " << std::endl;
	std::cout << nstr << std::endl;
	
	return 0;
}