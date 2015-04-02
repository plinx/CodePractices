#ifndef OOP_h
#define OOP_h

class Value 
{
	friend class _int;
	friend class _string;
public:
	virtual Value add(Value var) { return var; }
	virtual Value addInt(_int i) const;
	virtual Value addStr(_string s) const;
};

class _int : public Value
{
	friend class _string;
public:
	int _i;
	_int(int i) : _i(i) {}
	~_int() = default;

	Value add(Value var)
	{
		return var.addInt(*this);
	}
	Value addInt(_int i) const
	{
		return _int(i._i + _i);
	}
};

class _string : public Value
{
public:
	std::string _s;
	_string(std::string s) : _s(s) {}
	~_string() = default;

	Value add(Value var) 
	{
		return var.addStr(*this);
	}
	Value addInt(_int i) const
	{
		char tmp[32];
		sprintf_s(tmp, "%d", i._i);
		std::string ts(tmp);
		return _string(_s + ts);
	}
	Value addStr(_string s) const
	{
		return _string(s._s + _s);
	}
};

#endif