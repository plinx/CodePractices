#include <iostream>

#define PI 3.14159

using namespace std;

int main()
{
	int num;
	float x, y;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		cout << "Property " << i + 1 << ": This property will begin eroding in year ";
		cout << (int)(PI * (x * x + y * y) / 100) + 1<< "." << endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}

