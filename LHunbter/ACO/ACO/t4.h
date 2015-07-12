#ifndef t4_h
#define t4_h

void replace_blank(char* str, int len)
{
	if (str == nullptr && len <= 0) return;

	int orglen = 0;
	int num = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++orglen;
		if (str[i] == ' ') ++num;
		++i;
	}

	int newlen = orglen + 2 * num;
	if (newlen > len || newlen == orglen) return;

	while (orglen >= 0)
	{
		if (str[orglen] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
			str[newlen--] = str[orglen];
		--orglen;
	}
}

void t4()
{
	char str[100] = "We are happy.";

	replace_blank(str, sizeof(str));
	printf("%s\n", str);
	
}

#endif