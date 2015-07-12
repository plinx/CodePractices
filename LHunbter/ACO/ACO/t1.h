#ifndef t1_h
#define t1_h

class mString
{
public:
	mString(char* pData = nullptr);
	mString(const mString& str);
	~mString(void) = default;

	char* data() { return _data; }
	mString operator=(const mString &rhs);
private:
	char* _data;
};

mString::mString(char* pData) : _data(pData) {}

mString::mString(const mString& str)
{
	_data = new char[strlen(str._data) + 1];
	strcpy(_data, str._data);
}

mString mString::operator=(const mString &rhs)
{
	if (_data != rhs._data)
	{
		mString temp(rhs);

		char* tdata = temp._data;
		temp._data = _data;
		_data = tdata;
	}

	return *this;
}

void t1()
{
	mString str1("test");
	mString str2;

	str2 = str1;

	printf("%s\n", str1.data());
	printf("%s\n", str2.data());
}

#endif