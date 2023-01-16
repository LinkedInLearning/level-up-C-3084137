#include <stdio.h>
#include <stdlib.h>

char *left(char *s, int len)
{
	char *out = (char *)malloc(sizeof(char) * len + 1);

	for (int i = 0; i < len; i++)
	{
		*(out + i) = *(s + i);
	}
	*(out + len) = '\0';

	return out;
}

char *right(char *s, int len)
{
	char *out = (char *)malloc(sizeof(char) * len + 1);

	int x;
	for (x = 0;; x++)
	{
		if (*(s + x) == 0)
			break;
	}

	for (int i = 0; i < x - len; i++)
	{
		*(out + i) = *(s + i + x - len);
	}
	*(out + len) = '\0';

	return out;
}

char *mid(char *s, int offset, int len)
{
	char *out = (char *)malloc(sizeof(char) * len + 1);

	for (int i = 0; i < len; i++)
	{
		*(out + i) = *(s + i + offset-1);
	}
	*(out + len) = '\0';

	return out;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, left(string, 16));
	printf("Right %d characters: %s\n", 18, right(string, 18));
	printf("Middle %d characters: %s\n", 11, mid(string, 13, 11));

	return (0);
}
