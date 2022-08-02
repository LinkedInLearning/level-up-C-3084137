#include <stdio.h>

int main()
{
	int hail,count;

	/* gather input */
	printf("Enter the starting value: ");
	scanf("%d",&hail);
	/* eliminate zero and negative values */
	if( hail < 1 )
		return(1);

	/* output sequence */
	count = 1;
	printf("Hailstone sequence: ");
	while( hail != 1 )
	{
		printf("%d, ",hail);
		if( hail%2 )
		{
			/* odd */
			hail = (hail*3) + 1;	/* three times, plus one */
		}
		else
		{
			/* even */
			hail /= 2;				/* half the value */
		}
		count++;
	}
	printf("%d\n",hail);
	printf("Sequence length: %d\n",count);

	return(0);
}
