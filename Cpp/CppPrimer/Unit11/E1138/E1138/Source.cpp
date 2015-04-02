#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::ifstream; using std::string; using std::unordered_map;
using std::istringstream;
using std::cin; using std::cout; using std::endl;

void word_transform(ifstream&, ifstream&);
unordered_map<string, string> buildMap(ifstream&);
const string &transform(const string&, const unordered_map<string, string>&);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Input error : no enough input files." << endl;
		cout << "Usage : Exxx.exe <unordered_map_rules file> <tran file>" << endl;
		return -1;
	}
	ifstream mfile(argv[1]);	//E1136: if there is a unordered_map line without value, program will abort
	ifstream ifile(argv[2]);

	word_transform(mfile, ifile);

	return 0;
}

void word_transform(ifstream &unordered_map_file, ifstream &input_file)
{
	auto unordered_map_rules = buildMap(unordered_map_file);
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
			cout << transform(word, unordered_map_rules);
		}
	}
}

unordered_map<string, string> buildMap(ifstream &unordered_map_file)
{
	unordered_map<string, string> unordered_map_rules;
	string key;
	string value;

	while (unordered_map_file >> key && getline(unordered_map_file, value))
	{
		if (value.size() > 1)
		{
			//unordered_map_rules[key] = value.substr(1);
			unordered_map_rules.insert({ key, value.substr(1) }); //E1135: same with unordered_map_rulse[key]
		}
		else
		{
			throw std::runtime_error("no rule for " + key);
		}
	}

	return unordered_map_rules;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
	auto unordered_map_it = m.find(s);	//E1134: if use m[s] instead of m.find
	// string s will insert into m when could not find s
	if (unordered_map_it != m.end())
	{
		return unordered_map_it->second;
	}
	else
	{
		return s;
	}
}