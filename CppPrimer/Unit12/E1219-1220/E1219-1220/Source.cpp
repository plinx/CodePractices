#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>

using std::vector; using std::string; using std::initializer_list;
using std::shared_ptr; using std::make_shared; using std::weak_ptr;
using std::ifstream; using std::cin; using std::cout; using std::endl;
 
class StrBlobPtr;
class StrBlob {
public:
	friend class StrBlobPtr;
	typedef vector<string>::size_type size_type;

	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

	void push_back(const std::string &pstr) { data->push_back(pstr); }
	size_type size() const { return data->size(); }
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	shared_ptr<vector<string>> data;
	void check(size_type sz, const string &msg) const;
};

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &strBlob, size_t sz = 0) : wptr(strBlob.data), curr(sz) {}

	string &deref() const;
	StrBlobPtr &inc();

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr.");
	}
	if (sz > ret->size())
	{
		throw std::out_of_range(msg);
	}
	return ret;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{ 
	auto ret = StrBlobPtr(*this, data->size()); 
	return ret; 
}

string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end.");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::inc()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "No input files." << endl;
		cout << "Usage : Exxx.exe <input file>." << endl;
		return -1;
	}

	ifstream ifs(argv[1]);
	StrBlob strBlob;
	StrBlobPtr strP(strBlob);
	string str;

	while (ifs >> str)
	{
		strBlob.push_back(str);
		cout << strP.deref() << endl;
		strP.inc();
	}

	return 0;
}