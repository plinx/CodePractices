#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> monlist;
	monlist["pop"] = 0; monlist["no"] = 1; monlist["zip"] = 2;
	monlist["zotz"] = 3; monlist["tzec"] = 4; monlist["xul"] = 5;
	monlist["yoxkin"] = 6; monlist["mol"] = 7; monlist["chen"] = 8;
	monlist["yax"] = 9; monlist["zac"] = 10; monlist["ceh"] = 11;
	monlist["mac"] = 12; monlist["kankin"] = 13; monlist["muan"] = 14; 
	monlist["pax"] = 15; monlist["koyab"] = 16; monlist["cumhu"] = 17;
	monlist["uayet"] = 18;
	string daylist[] = {
		"imix", "ik", "akbal", "kan", "chicchan",
		"cimi", "manik", "lamat", "muluk", "ok",
		"chuen", "eb", "ben", "ix", "mem",
		"cib", "caban", "eznab", "canac", "ahau"
	};

	string Month;
	int num;
	int NumberOfTheDay;
	int Year, day, sum;

	cin >> num;
	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> NumberOfTheDay >> Month >> Month >> Year;	// cin twice Month to skip "."
		sum = NumberOfTheDay + monlist[Month] * 20  + Year * 365;

		Year = sum / 260;	// Tzolkin year;
		day = sum % 260;	// Tzolkin day;
		cout << day % 13 + 1 << " " << daylist[day % 20] << " " << Year << endl;
	}

	return 0;
}

