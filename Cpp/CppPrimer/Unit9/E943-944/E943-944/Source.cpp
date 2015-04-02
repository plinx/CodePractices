#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

void replace_str(string&, string, string);
void new_replace_str(string&, string, string);

int main()
{
	string str11("thotho");
	string str12("thotho");
	string str21("thru");
	string str22("thru");
	string str31("thruasdba");
	string str32("thruasdba");
	replace_str(str11, "tho", "though");
	replace_str(str21, "thru", "through");
	replace_str(str31, "thru", "through");
	new_replace_str(str12, "tho", "though");
	new_replace_str(str22, "thru", "through");
	new_replace_str(str32, "thru", "through");
	cout << "replace_str() : " << endl;
	cout << str11 << endl;
	cout << str21 << endl;
	cout << str31 << endl;
	cout << "new_replace_str() : " << endl;
	cout << str12 << endl;
	cout << str22 << endl;
	cout << str32 << endl;

	return 0;
}

void replace_str(string &s, string oldVal, string newVal)
{
	auto cur = s.begin();
	auto oldcur = oldVal.cbegin();
	while (cur != s.end())
	{
		if (oldcur == oldVal.cend())
		{
			cur = s.insert(cur, newVal.cbegin() + oldVal.size(), newVal.cend());
			cur = cur + newVal.size() - oldVal.size();
			--cur;
			oldcur = oldVal.cbegin();
			//std::cout << "oldcur == oldVal.cent()" << std::endl;
		}
		else if (*cur == *oldcur)
		{
			++oldcur;
			//std::cout << "++oldcur" << std::endl;
		}
		else
		{
			oldcur = oldVal.cbegin();
			//std::cout << "oldcur = cbegin()" << std::endl;
		}

		++cur;
	}

	if (oldcur == oldVal.cend())
	{
		cur = s.insert(cur, newVal.cbegin() + oldVal.size(), newVal.cend());
	}
}

void new_replace_str(string &s, string oldVal, string newVal)
{
	auto pos = s.find(oldVal);
	while (pos != string::npos)
	{
		s.replace(pos, oldVal.size(), newVal);
		pos += newVal.size();
		pos = s.find(oldVal, pos);
	}
}
