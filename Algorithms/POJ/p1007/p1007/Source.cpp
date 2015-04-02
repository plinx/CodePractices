#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct DNA
{
	string dna;
	int inversion;
};

int cmp(const void *lh, const void *rh)
{
	DNA *l = (DNA *)lh;
	DNA *r = (DNA *)rh;
	return (l->inversion - r->inversion);
}

int main()
{
	DNA data[100];
	string str;
	char temp;
	int num, line;
	int inversion = 0;

	cin >> num >> line;
	for (int i = 0; i < line; i++)
	{
		cin >> str;
		inversion = 0;
		for (int j = 0; j < num; j++)
		{
			temp = str[j];
			for (int k = j; k < num; k++)
			{
				if (temp > str[k])
					inversion++;
			}
		}
		data[i].dna = str;
		data[i].inversion = inversion;
	}
	qsort(data, line, sizeof(struct DNA), cmp);

	for (int i = 0; i < line; i++)
	{
		cout << data[i].dna << endl;
	}

	return 0;
}