#include <stdio.h>

char *ordinal(int v)
{
	/* create this function */
}

int main()
{
	int c;

	for( c=1; c<=20; c++ )
	{
		printf("%3d\t%3d\t%3d\t%3d\t%3d\n",
				c,
				c+20,
				c+40,
				c+60,
				c+80
			  );
	}

	return(0);
}
