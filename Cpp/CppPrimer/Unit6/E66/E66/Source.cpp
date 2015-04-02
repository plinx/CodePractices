#include <iostream>

// 形参在调用函数时初始化开始生命周期，函数完成时结束生命周期
// 局部变量从每次声明开始生命周期，函数完成时结束生命周期
// 局部静态变量从第一声明开始生命周期，最后一次调用函数时结束生命周期


void func(int x);

int main()
{
	int x;
	std::cin >> x;
	func(x);
	func(x);

	return 0;
}

void func(int x)
{
	int tmpi = 0;
	static int statici = 0;

	tmpi += x;
	statici += x;

	std::cout << "tmpi : " << tmpi << std::endl;
	std::cout << "statici : " << statici << std::endl;
}