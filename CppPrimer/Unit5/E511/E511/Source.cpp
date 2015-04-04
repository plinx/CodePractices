#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	int sCnt = 0, tCnt = 0, nCnt = 0;
	char ch;

	while ((ch = cin.get()) != EOF)
	{
		if (ch == ' ') {
			++sCnt;
		}
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
		case ' ':
			++sCnt;
			break;
		case '\t':
			++tCnt;
			break;
		case '\n':
			++nCnt;
			break;
		}
	}

	cout << "aCnt : " << aCnt << endl;
	cout << "eCnt : " << eCnt << endl;
	cout << "oCnt : " << oCnt << endl;
	cout << "iCnt : " << iCnt << endl;
	cout << "uCnt : " << uCnt << endl;
	cout << "sCnt : " << sCnt << endl;
	cout << "tCnt : " << tCnt << endl;
	cout << "nCnt : " << nCnt << endl;

	return 0;
}