#include <stdio.h>

int leapyear(int year)
{
	if( year%400==0 )
		return(1);
	if( year%100==0 )
		return(0);
	if( year%4==0 )
		return(1);
	return(0);
}

int main()
{
	int y;

	printf("Leap years from 1583 through 2101:\n");
	for(y=1583;y<=2101;y++)
	{
		if( leapyear(y)==1 )
			printf("%d\n",y);
	}

	return(0);
}

