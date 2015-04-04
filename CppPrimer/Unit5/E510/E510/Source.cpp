#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;

	while (cin >> ch)
	{
		switch (ch) {
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		}
	}

	cout << "aCnt : " << aCnt << endl;
	cout << "eCnt : " << eCnt << endl;
	cout << "oCnt : " << oCnt << endl;
	cout << "iCnt : " << iCnt << endl;
	cout << "uCnt : " << uCnt << endl;

	return 0;
}