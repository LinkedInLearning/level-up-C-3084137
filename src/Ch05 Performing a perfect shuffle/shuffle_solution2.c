#include <stdio.h>
#include <string.h>

#define DECKSIZE 26
#define HALFDECK DECKSIZE/2

void shuffle(char *deck)
{
	char left[HALFDECK];
	char right[HALFDECK];
	int x;

	/* split the deck */
	for(x=0;x<HALFDECK;x++)
	{
		left[x] = *(deck+x);
		right[x] = *(deck+HALFDECK+x);
	}

	/* shuffle the two halves into the original array*/
	for(x=0;x<HALFDECK;x++)
	{
		*(deck+(x*2)) = left[x];
		*(deck+(x*2)+1) = right[x];
	}
}

int main()
{
	char original_deck[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	char cards[DECKSIZE];
	int x,shuffles;
	
	printf("Original deck: %s\n",original_deck);
	/* create copy for shuffling */
	for(x=0;x<DECKSIZE;x++)
		cards[x] = original_deck[x];
	cards[x] = '\0';

	/* shuffle until decks match */
	shuffles = 0;
	do
	{
		shuffle(cards);
		shuffles++;
		printf("Shuffle %2d: %s\n",shuffles,cards);
	} while(strcmp(original_deck,cards)!=0);

	printf("It took a total of %d shuffles to restore the deck.\n",
			shuffles);

	return(0);
}

