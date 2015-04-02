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
		if (ch == 'a') 
		{
			aCnt++;
			continue;
		} 
		else if (ch == 'e') 
		{
			eCnt++;
			continue;
		}
		else if (ch == 'i') 
		{
			iCnt++;
			continue;
		}
		else if (ch == 'o')
		{
			oCnt++;
			continue;
		}
		else if (ch == 'u')
		{
			uCnt++;
			continue;
		}
	}

	cout << "aCnt : " << aCnt << endl;
	cout << "eCnt : " << eCnt << endl;
	cout << "oCnt : " << oCnt << endl;
	cout << "iCnt : " << iCnt << endl;
	cout << "uCnt : " << uCnt << endl;

	return 0;
}