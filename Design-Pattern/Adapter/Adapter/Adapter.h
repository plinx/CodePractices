#ifndef Adapter_h
#define Adapter_h

class Target
{
public:
	Target() = default;
	virtual ~Target() = default;
	virtual void Request() { std::cout << "Target::Request" << std::endl; }
};

class Adaptee
{
public:
	Adaptee() = default;
	~Adaptee() = default;
	void AdapteeRequest() { std::cout << "Adaptee::Request" << std::endl; }
};

class Adapter1 : public Target, private Adaptee
{
public:
	Adapter1() = default;
	~Adapter1() = default;
	void Request() { return this->AdapteeRequest(); }
};

class Adapter2 : public Target
{
public:
	Adapter2(Adaptee* a) : adaptee(a) {}
	~Adapter2() = default;
	void Request() { return adaptee->AdapteeRequest(); }
private:
	Adaptee* adaptee;
};

#endif