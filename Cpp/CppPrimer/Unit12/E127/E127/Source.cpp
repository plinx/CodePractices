#include <iostream>
#include <memory>
#include <vector>

using std::vector; using std::shared_ptr; using std::istream; using std::make_shared;
using std::cin; using std::cout; using std::endl;

shared_ptr<vector<int>> get_input(istream&);
void print_input(shared_ptr<vector<int>>&);

int main()
{
	auto sp = get_input(cin);
	print_input(sp);

	return 0;
}

shared_ptr<vector<int>> get_input(istream &in)
{
	vector<int> sptr;
	int input;

	while (in >> input)
	{
		sptr.push_back(input);
	}

	return make_shared<vector<int>>(sptr);
}

void print_input(shared_ptr<vector<int>> &sptr)
{
	for (auto &s : *sptr)
	{
		cout << s << " ";
	}
	cout << endl;
}