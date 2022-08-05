#include <stdio.h>

int main()
{
	float amount[] = {
		0.49, 1.27, 0.75, 1.31, 0.83
	};
	int x,coins,quarters, dimes, nickels, pennies;

	for( x=0; x<5; x++ )
	{
		/* initialize coins */
		quarters = dimes = nickels = pennies = 0;

		printf("Making change for: $%.2f\n",amount[x]);
		/* use integers for looping */
		coins = amount[x] * 100;
		while( coins >= 25 )
		{
			quarters++;
			coins -= 25;
		}
		while( coins >= 10 )
		{
			dimes++;
			coins -= 10;
		}
		while( coins >= 5 )
		{
			nickels++;
			coins -= 5;
		}
		pennies = coins;

		printf("\t%d quarters, %d dimes, %d nickels, %d pennies\n",
				quarters,
				dimes,
				nickels,
				pennies
			  );
	}

	return(0);
}
