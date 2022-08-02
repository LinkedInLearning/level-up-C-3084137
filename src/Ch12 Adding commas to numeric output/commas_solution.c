#include <stdio.h>
#include <string.h>

/* add commas to the integer value every 3 character positions */
void commify(char *s, int v)
{
	char temp[15];
	int len,c,t;

	/* convert value to string */
	sprintf(temp,"%d",v);

	/* duplicate the string, but with commas */
	len = strlen(temp);
	c = t = 0;				/* index variables */
	while(temp[t]!='\0')
	{
		if( len % 3 )		/* comma every three characters */
		{
			*(s+c) = temp[t];		/* no comma, so copy */
		}
		else
		{
			if( t != 0 )			/* avoid a trailing comma */
			{
				*(s+c) = ',';		/* add the comma */
				c++;
			}
			*(s+c) = temp[t];		/* copy the following character */
		}
		c++;
		t++;
		len--;
	}
	*(s+c) = '\0';			/* cap the string */
}

int main()
{
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};
	char withcomma[15];
	int x;

	for( x=0; x<10; x++ )
	{
		commify(withcomma,values[x]);
		printf("%10d:%15s\n", values[x], withcomma);
	}

	return(0);
}
