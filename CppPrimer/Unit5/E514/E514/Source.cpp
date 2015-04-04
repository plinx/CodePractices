#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str, tmp, mstr;
	int cnt = 1, mcnt = 1;

	cin >> str;
	tmp = str;
	mstr = str;

	while (cin >> str) {
		if (str != tmp) {
			if (mcnt <= cnt) {
				mcnt = cnt;
				mstr = tmp;
			}
			tmp = str;
			cnt = 1;
		} else {
			++cnt;
		}
	}
	if (mcnt <= cnt) {
		mcnt = cnt;
		mstr = tmp;
	}

	cout << "mstr : " << mstr << endl;
	cout << "mcnt : " << mcnt << endl;

	return 0;
}