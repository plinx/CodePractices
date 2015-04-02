#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;;
using std::endl;

void judge_str(const string &str);
void tolower_str(string &str);

int main()
{
	string str;
	std::getline(cin, str);

	judge_str(str);
	tolower_str(str);

	return 0;
}

void judge_str(const string &str)
{
	for (auto &s : str) {
		if (s == toupper(s)) {
			if (s == ' ') continue;
			cout << "There is " << s << " in string." << endl;
			break;
		}
	}
}

void tolower_str(string &str)
{
	for (auto &s : str) {
		s = tolower(s);
	}
	cout << "string after tolower(s) :" << str << endl;
}