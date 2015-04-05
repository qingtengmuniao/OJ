#include <stdio.h>

int main()
{
	char s[5];
	int i;

	for (i = 0; i < 2; ++i)
	{
		fgets(s, sizeof(s), stdin);
		printf("%s\n", s);
	}

	return 0;
}
