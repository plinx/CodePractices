#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int tmp, sum = 0, si = 0;
	vector<int> ivec;

	while (cin >> tmp) {
		ivec.push_back(tmp);
	}

	for (int i = 0; i < ivec.size(); i++) {
		if (i == ivec.size() - 1) {
			cout << "leave " << ivec[i] << endl;
			break;
		}
		cout << ivec[i] << " + " << ivec[i + 1] << " = "
			<< ivec[i] + ivec[i + 1] << endl;
		i++;
	}

	for (int i = 0; i <= ivec.size()/2; i++) {
		if (i == ivec.size()/2) {
			cout << "leave " << ivec[i] << endl;
			break;
		}
		cout << ivec[i] << " + " << ivec[ivec.size() - i - 1] << " = "
			<< ivec[i] + ivec[ivec.size() - i - 1] << endl;
	}

	return 0;
}