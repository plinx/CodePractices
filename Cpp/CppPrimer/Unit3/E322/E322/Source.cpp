#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string text = "some string";

	cout << "old string : " << text << endl;
	cout << "new string : ";

	for (auto s = text.begin(); s != text.end() && *s != ' '; ++s) {
		*s = toupper(*s);
		cout << *s;
	}
	cout << endl;

	return 0;
}