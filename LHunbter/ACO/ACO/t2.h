#ifndef t2_h
#define t2_h

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

void t2()
{
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();

	printf("s1 = %p, s2 = %p\n", s1, s2);
}

#endif