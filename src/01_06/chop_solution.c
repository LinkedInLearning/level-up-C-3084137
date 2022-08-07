#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
	char *buf;
	int x;

	/* allocate storage */
	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	for(x=0;x<len;x++)			/* copy len chars */
		*(buf+x) = *(s+x);
	*(buf+x) = '\0';			/* cap the string */

	return(buf);
}

char *right(char *s,int len)
{
	char *buf;
	char *start;
	int x;

	/* allocate storage */
	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	/* find the end of the string */
	start = s;
	while(*start!='\0')
	   start++;
	/* backup */
	for(x=0;x<len;x++)
		start--;

	/* you could return start here, but I want consistency */
	for(x=0;x<len;x++)
		*(buf+x) = *(start+x);
	*(buf+x) = '\0';			/* cap the string */

	return(buf);
}

char *mid(char *s,int offset, int len)
{
	char *buf;
	int x;

	/* allocate storage */
	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	/* copy the string */
	for(x=0;x<len;x++)
	{
		*(buf+x) = *(s+offset+x);	/* remember, offset 0 is the string start */
		if( *(buf+x)=='\0')		/* avoid overflow */
			break;
	}
	*(buf+x) = '\0';			/* cap the string */

	return(buf);
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,12,11));

	return(0);
}
