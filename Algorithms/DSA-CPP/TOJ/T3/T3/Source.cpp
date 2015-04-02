#include <cstdio>
#include <cstring>
#include <cctype>

#define LEN 4096

int main()
{
	char text[LEN + 1];
	gets(text);

	int cnt[26] = { 0 };
	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		char c = text[i];
		if (isalpha(c))
			cnt[toupper(c) - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] != 0)
			printf("%c: %d\n", i + 'A', cnt[i]);
	}

	return 0;
}
