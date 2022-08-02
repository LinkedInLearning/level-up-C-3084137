#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
}

char *right(char *s,int len)
{
}

char *mid(char *s,int offset, int len)
{
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,13,11));

	return(0);
}
