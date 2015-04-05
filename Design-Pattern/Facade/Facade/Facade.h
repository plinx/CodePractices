#ifndef Facade_h
#define Facade_h

class SubSys1
{
public:
	SubSys1() = default;
	~SubSys1() = default;
	void Operation() { std::cout << "SubSys1 operation." << std::endl; }
};

class SubSys2
{
public:
	SubSys2() = default;
	~SubSys2() = default;
	void Operation() { std::cout << "SubSys2 operation." << std::endl; }
};

class Facade
{
public:
	Facade()
	{
		sub1 = new SubSys1();
		sub2 = new SubSys2();
	}
	~Facade()
	{
		delete sub1;
		delete sub2;
	}

	void OperationWrapper()
	{
		sub1->Operation();
		sub2->Operation();
	}
private:
	SubSys1* sub1;
	SubSys2* sub2;
};

#endif