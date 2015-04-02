#include <iostream>

int main()
{
	int curVal = 0, val = 0;
	if (std::cin >> curVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == curVal)
				++cnt;
			else {
				std::cout << curVal << " occurs " << cnt << " times" << std::endl;
				curVal = val;
				cnt = 1;
			}
		}
		std::cout << curVal << " occurs " << cnt << " times" << std::endl;
	}
	return 0;
}