#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;

bool valid(const string&);

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main(int argc, char *argv[])
{
	if (!argv[1])
	{
		cout << "No input files." << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	ostringstream formatted, badNums;

	while (std::getline(ifs, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);

		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);

		people.push_back(info);
	}

	for (const auto &p : people)
	{
		for (const auto &phone : p.phones)
		{
			if (!valid(phone))
			{
				badNums << phone << " ";
			}
			else
			{
				formatted << phone << " ";
			}
		}
		if (badNums.str().empty())
			cout << "Names : " << p.name << endl
				 << "Phones :" << formatted.str() << endl;
		else
			cerr << "input error : " << p.name << endl
			<< "invalid numbers(s) : " << badNums.str() << endl;
		
	}
	return 0;
}

bool valid(const string &str)
{
	for (auto &s : str)
	{
		if ((int)s < 48 || (int)s > 57 )
		{
			return false;
		}
	}
	return true;
}