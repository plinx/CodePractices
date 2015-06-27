#ifndef dp_h
#define dp_h

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INFNUM = 2147483648;

int cur_rod(vector<int> &p, int n)
{
	if (n == 0) return 0;
	int q = -INFNUM;
	for (int i = 0; i < n; i++)
		q = max(q, p[i] + cur_rod(p, n - i - 1));

	return q;
}

int memoized_cur_rod_aux(vector<int> &p, int n, vector<int> &r)
{
	if (n == 0) return 0;
	if (0 < r[n - 1]) return r[n - 1];
	int q = (n != 0) ? r[n - 1] : 0;

	for (int i = 0; i < n; i++)
		q = max(q, p[i] + memoized_cur_rod_aux(p, n - i - 1, r));

	r[n - 1] = q;
	return q;
}

int memoized_cur_rod(vector<int> &p, int n)
{
	vector<int> r(n, -INFNUM);
	return memoized_cur_rod_aux(p, n, r);
}

int bottom_up_cur_rod(vector<int> &p, int n)
{
	vector<int> r(n + 1);

	int q;
	for (int j = 1; j < n + 1; j++)
	{
		q = -INFNUM;
		for (int i = 0; i < j; i++)
			q = max(q, p[i] + r[j - i - 1]);
		r[j] = q;
	}
	return r[n];
}




#endif