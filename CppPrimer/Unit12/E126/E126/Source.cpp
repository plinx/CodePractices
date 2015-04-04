#include <iostream>
#include <vector>

using std::vector; using std::istream;
using std::cin; using std::cout; using std::endl;
vector<int> *get_input(istream&);
void print_input(vector<int>*);

int main()
{
	auto p = get_input(cin);
	print_input(p);

	return 0;
}

vector<int> *get_input(istream &in)
{
	int input;
	vector<int> *pv = new vector<int>;
	while (in >> input)
	{
		pv->push_back(input);
	}

	return pv;
}

void print_input(vector<int> *pv)
{
	for (auto &v : *pv)
	{
		cout << v << " ";
	}
	cout << endl;
	delete pv;
	pv = nullptr;
}