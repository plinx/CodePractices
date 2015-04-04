#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
	map<string, list<int>> word;

	map<vector<int>::iterator, int> mvec;
	map<list<int>::iterator, int> mlst;

	vector<int> vi;
	mvec.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));
	
	list<int> li;
	//mlst.insert(pair<list<int>::iterator, int>(li.begin(), 0)); //see declaration of 'std::operator <'

	return 0;
}