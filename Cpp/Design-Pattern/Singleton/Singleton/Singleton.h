#ifndef Singleton_h
#define Singleton_h

class Singleton
{
public:
	static Singleton& createSingleton()
	{
		static Singleton tmp;
		return tmp;
	}
protected:
	Singleton() { std::cout << "Creating Singleton." << std::endl; }
};

#endif