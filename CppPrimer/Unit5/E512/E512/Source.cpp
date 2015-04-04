#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int ff = 0, fl = 0, fi = 0, f = 0;
	char ch;

	while ((ch = cin.get()) != EOF)
	{
		switch (ch) {
		case 'f':
			if (f == 0) 
				++f;
			else {
				++ff;
				f = 0;
			}
			break;
		case 'l':
			if (f != 0) {
				f = 0;
				++fl;
			}
			break;
		case 'i':
			if (f != 0) {
				f = 0;
				++fi;
			}
			break;
		default:
			if (f != 0)
				f = 0;
			break;
		}
	}

	cout << "ff : " << ff << endl;
	cout << "fl : " << fl << endl;
	cout << "fi : " << fi << endl;

	return 0;
}