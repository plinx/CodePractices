#include <iostream>

// �β��ڵ��ú���ʱ��ʼ����ʼ�������ڣ��������ʱ������������
// �ֲ�������ÿ��������ʼ�������ڣ��������ʱ������������
// �ֲ���̬�����ӵ�һ������ʼ�������ڣ����һ�ε��ú���ʱ������������


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