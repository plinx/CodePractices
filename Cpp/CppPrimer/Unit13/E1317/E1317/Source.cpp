#include <iostream>

class numbered {
public:
	friend void f(numbered&);
	numbered();
	numbered& operator=(const numbered &num)
	{
		static int j = 10;
		++j;
		mysn = j;
		return *this;
	}

private:
	int mysn;
};

numbered::numbered()
{
	static int i = 0;
	++i;
	mysn = i;
}

void f(numbered &n)
{
	std::cout << n.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}