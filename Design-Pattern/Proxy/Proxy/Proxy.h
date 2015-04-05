#ifndef Proxy_h
#define Proxy_h

class Subject
{
public:
	virtual ~Subject() = 0;
	virtual void Request() = 0;
protected:
	Subject() = default;
};
Subject::~Subject() = default;

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject() = default;
	void Request() { std::cout << "ConcreteSubject request ..." << std::endl; }
};

class Proxy
{
public:
	Proxy() = default;
	~Proxy() = default;

	Proxy(Subject* sub) : subject(sub) {}
	void Request()
	{
		std::cout << "Proxy request ..." << std::endl;
		subject->Request();
	}
private:
	Subject* subject;
};

#endif