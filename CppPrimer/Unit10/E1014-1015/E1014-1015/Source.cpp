#include <iostream>

int lambda_sum(int);

int main()
{
	auto sum = [](int a, int b) { return a + b; };
	std::cout << sum(2, 3) << std::endl;
	std::cout << lambda_sum(5) << std::endl;
	
	return 0;
}

int lambda_sum(int i)
{
	int li;
	auto lsum = [i] (int li) { return i + li; };
	std::cout << "enter lambda int : ";
	std::cin >> li;
	return lsum(li);
}