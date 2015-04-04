#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::string; using std::vector;

int main()
{
	vector<string> vsi = { "123", "456", "789" };
	vector<string> vsd = { "1.23", "4.56", "7.89" };
	int vi = 0;
	double vd = 0;

	for (auto &i : vsi)
	{
		vi += stoi(i);
	}
	cout << "vector<string> to int sum : " << vi << endl;
	for (auto &d : vsd)
	{
		vd += stod(d);
	}
	cout << "vector<string> to double sum : " << vd << endl;

	return 0;
}