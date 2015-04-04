#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while (std::getline(cin, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}

		people.push_back(info);
	}

	for (auto &p : people)
	{
		std::cout << "Name : " << p.name << std::endl << "Phones : ";
		for (auto &phone : p.phones)
		{ 
			std::cout << phone << " ";
		}
		std::cout << std::endl;
	}
}