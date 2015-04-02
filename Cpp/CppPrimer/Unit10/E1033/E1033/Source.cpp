#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		cout << "No enough file variable." << endl;
		cout << "Usage : E1033.exe <input file> <odd output file> <even output file>" << endl;
		return -1;
	}
	ifstream ifs(argv[1]);
	ofstream odd_ofs(argv[2]), even_ofs(argv[3]);

	istream_iterator<int> is_it(ifs), eof;
	ostream_iterator<int> odd_it(odd_ofs, " "), even_it(even_ofs, " ");

	while (is_it != eof)
	{
		if (*is_it % 2)
		{
			odd_it = *is_it;
		}
		else
		{
			even_it = *is_it;
		}
		++is_it;
	}

	return 0;
}