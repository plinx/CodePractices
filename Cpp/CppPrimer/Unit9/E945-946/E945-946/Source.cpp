#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

string mix_str(string, string, string);
string new_mix_str(string, string, string);

int main()
{
	string str("test");
	cout << mix_str(str, "Mr.", "Jr.") << endl;
	cout << new_mix_str(str, "Mr.", "Jr.") << endl;
	return 0;
}

string mix_str(string s, string prefix, string suffix)
{
	string str = s;
	str.insert(0, prefix);
	str.append(suffix);

	return str;
}

string new_mix_str(string s, string prefix, string suffix)
{
	string::size_type pos = 0;
	string str;
	str.insert(pos, prefix);
	pos += prefix.size();
	str.insert(pos, s);
	pos += s.size();
	str.insert(pos, suffix);

	return str;

}