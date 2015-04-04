#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	std::vector<double> vec = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl; 
	// using 0 will convert double to int
	std::cout << std::accumulate(vec.begin(), vec.end(), 0.0) << std::endl;

	return 0;
}