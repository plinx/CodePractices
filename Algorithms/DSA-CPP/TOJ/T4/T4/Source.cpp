#include <cstdio>

int main()
{
	int h1, h2, m1, m2, s1, s2;
	int total;

	scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
	total = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
	if (total < 0)
		total += 24 * 3600;

	printf("%d", total);

	return 0;
}