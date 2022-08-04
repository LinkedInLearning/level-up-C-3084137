#include <stdio.h>
#include <string.h>

int main()
{
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char deck[27],shuffle[27];
	const int shufsize = 13;		/* half the deck size */
	int count,s,d;

	printf("Original deck: %s\n",original);
	/* duplicate the original for shuffling */
	strcpy(deck,original);
	count = 0;
	while(1)
	{
		/* s skips 2; d increments */
		for( d=0,s=0; d<shufsize ; d++,s+=2 )
		{
			shuffle[s] = deck[d];
			shuffle[s+1] = deck[d+shufsize];
		}
		shuffle[s] = '\0';		/* cap the string */
		count++;
		printf("%2d: %s\n",count,shuffle);
		/* stop if the deck is restored */
		if( strcmp(original,shuffle)==0 )
			break;
		/* reset the deck to start over */
		strcpy(deck,shuffle);
	}
	printf("Deck restored after %d iterations\n",count);

	return(0);
}
