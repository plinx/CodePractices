#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using std::ifstream; using std::string; using std::map; 
using std::istringstream;
using std::cin; using std::cout; using std::endl;

void word_transform(ifstream&, ifstream&);
map<string, string> buildMap(ifstream&);
const string &transform(const string&, const map<string, string>&);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Input error : no enough input files." << endl;
		cout << "Usage : Exxx.exe <map_rules file> <tran file>" << endl;
		return -1;
	}
	ifstream mfile(argv[1]);	//E1136: if there is a map line without value, program will abort
	ifstream ifile(argv[2]);

	word_transform(mfile, ifile);

	return 0;
}

void word_transform(ifstream &map_file, ifstream &input_file)
{
	auto map_rules = buildMap(map_file);
	string text;

	while (getline(input_file, text))
	{
		istringstream stream(text);
		string word;
		bool fword = true;

		while (stream >> word)
		{
			if (fword)
			{
				fword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, map_rules);
		}
	}
}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> map_rules;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
		{
			//map_rules[key] = value.substr(1);
			map_rules.insert({ key, value.substr(1) }); //E1135: same with map_rulse[key]
		}
		else
		{
			throw std::runtime_error("no rule for " + key);
		}
	}

	return map_rules;
}

const string &transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);	//E1134: if use m[s] instead of m.find
								// string s will insert into m when could not find s
	if (map_it != m.end())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}
}