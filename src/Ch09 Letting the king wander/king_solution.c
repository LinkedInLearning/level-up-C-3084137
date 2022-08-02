#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GSIZE 8

struct loc {
	int row;
	int col;
};
		
/* output the game grid */
void output(int t, struct loc k)
{
	int row,col;

	/* grid header */
	if( t==0 )
		puts("Start:");
	else
		printf("Turn %d:\n",t);

	/* grid */
	for( row=0; row<GSIZE; row++ )
	{
		for( col=0; col<GSIZE; col++ )
		{
			if( row==k.row && col==k.col )
				printf(" K ");
			else
				printf(" . ");
		}
		putchar('\n');
	}
}

/* move negative, positive, or zero */
int move(void)
{
	int r;

	r = (rand() % 3) - 1;
	return(r);
}

/* check to see if the king's location is safe */
int escaped(struct loc k)
{
	enum { FALSE, TRUE };

	if( k.row<0 )
		return(TRUE);
	if( k.row>=GSIZE )
		return(TRUE);
	if( k.col<0 )
		return(TRUE);
	if( k.col>=GSIZE )
		return(TRUE);
	return(FALSE);
}

/* main program */
int main()
{
	int turn = 0;
	struct loc king = { 3, 4};		/* fourth row, fifth column */

	/* seed randomizer */
	srand( (unsigned)time(NULL) );

	/* the loop terminates when the king wanders out */
	while(1)
	{
		/* show the grid */
		output(turn,king);
		/* move the king */
		king.row += move();
		king.col += move();
		/* check new position */
		if( escaped(king) )
			break;
		turn++;
	}
	printf("The king wandered off the grid after %d turns\n",turn);

	return(0);
}
