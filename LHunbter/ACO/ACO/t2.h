#ifndef t2_h
#define t2_h

#include <mutex>

class Singleton
{
private:
	Singleton() {}
public:
	static Singleton* getInstance()
	{
		static Singleton _instance;
		return &_instance;
	}
};

std::mutex mtx;

class Singleton1
{
private:
	Singleton1() {}
	static Singleton1* _instance;
public:
	static Singleton1* getInstance()
	{
		if (NULL == _instance)
		{
			mtx.lock();
			if (NULL == _instance)
				_instance = new Singleton1();
			mtx.unlock();
		}
		return _instance;
	}
};
Singleton1* Singleton1::_instance;

void t2()
{
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	Singleton1* s3 = Singleton1::getInstance();
	Singleton1* s4 = Singleton1::getInstance();

	printf("s1 = %p, s2 = %p\n", s1, s2);
	printf("s3 = %p, s4 = %p\n", s3, s4);
}

#endif