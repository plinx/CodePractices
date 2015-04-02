#include <iostream>
#include <cmath>

#define DOUBLE(x) (x * x)

using namespace std;

struct Color
{
	double R, G, B;
};

int main()
{
	Color colorset[16];
	double r, g, b;
	double d, tmp;
	int di;

	for (int i = 0; i < 16; i++)
	{
		cin >> colorset[i].R >> colorset[i].G >> colorset[i].B;
	}

	while (true)
	{
		cin >> r >> g >> b;

		if (r == -1)
			break;

		d = sqrt(DOUBLE(abs(colorset[0].R - r)) 
			+ DOUBLE(abs(colorset[0].G - g)) 
			+ DOUBLE(abs(colorset[0].B - b)));

		if (d == 0)
		{
			cout << "(" << r << "," << g << "," << b << ") maps to ";
			cout << "(" << r << "," << g << "," << b << ")" << endl;
			continue;
		}

		di = 0;
		for (int i = 1; i < 16; i++)
		{
			tmp = sqrt(DOUBLE(abs(colorset[i].R - r)) 
				+ DOUBLE(abs(colorset[i].G - g)) 
				+ DOUBLE(abs(colorset[i].B - b)));

			if (tmp == 0)
			{
				di = i;
				break;
			} 
			else if (d > tmp)
			{
				d = tmp;
				di = i;
			}
		}
		cout << "(" << r << "," << g << "," << b << ") maps to ";
		cout << "(" << colorset[di].R << "," << colorset[di].G << "," << colorset[di].B << ")" << endl;
	}

	return 0;
}
