#include <iostream>
#include <vector>

int main()
{
	int arr[10], carr[10];
	std::vector<int> varr(10), cvarr(10);

	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
		std::cout << "arr[" << i << "] :" << arr[i] << std::endl;
	}
	std::cout << "===================" << std::endl;

	for (int i = 0; i < 10; ++i) {
		carr[i] = arr[i];
		std::cout << "carr[" << i << "] :" << carr[i] << std::endl;
	}
	std::cout << "===================" << std::endl;

	for (int i = 0; i < 10; ++i) {
		varr[i] = i;
		std::cout << "varr[" << i << "] :" << varr[i] << std::endl;
	}
	std::cout << "===================" << std::endl;
	cvarr = varr;
	for (int i = 0; i < 10; ++i) {
		cvarr[i] = i;
		std::cout << "cvarr[" << i << "] :" << cvarr[i] << std::endl;
	}

	return 0;
}