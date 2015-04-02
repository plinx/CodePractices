#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//ifstream in("input.txt");
	vector<string> url_list;
	string cmd, url;
	vector<string>::size_type pos = 0;

	url_list.push_back("http://www.acm.org/");	// check the input carefully!!!
	while (cin >> cmd)
	{
		if (cmd == "VISIT")
		{
			cin >> url;
			cout << url << endl;
			if (pos < url_list.size() - 1)
				url_list.resize(pos + 1);
			url_list.push_back(url);
			pos++;
		}
		else if (cmd == "BACK")
		{
			if (pos > 0)
			{
				pos--;
				cout << url_list[pos] << endl;
			}
			else
			{
				cout << "Ignored" << endl;
			}
		}
		else if (cmd == "FORWARD")
		{
			if (pos < url_list.size() - 1)
			{
				pos++;
				cout << url_list[pos] << endl;
			}
			else
			{
				cout << "Ignored" << endl;
			}
		}
		else
			break;
	}

	return 0;
}