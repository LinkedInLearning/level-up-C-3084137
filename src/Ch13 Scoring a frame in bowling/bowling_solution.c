#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* structure must be declared external to be available
   in all functions */
struct frame {
	char b1, b2;
	int ball1, ball2, score;
};

/* generate a random value, 1 through pins */
int ball_roll(int pins)
{
	return( rand() % (pins + 1) );
}

void fill_frame(struct frame *f)
{
	/* get first ball */
	f->ball1 = ball_roll(10);		/* all 10 pins */

	/* check for a strike */
	if( f->ball1==10 )
	{
		f->b1 = ' ';			/* the first ball character is blank */
		f->b2 = 'X';			/* the second character is the strike */
		f->ball2 = 0;			/* initialize this value anyway */
		f->score = 10;			/* plus the next two balls */
	}
	else
	{
		/* Set the first ball's character. If zero,
		   the '-' is set as the character */
		f->b1 = f->ball1 ? f->ball1+'0' : '-';
		/* roll the second ball */
		f->ball2 = ball_roll(10-f->ball1);
		/* check for a spare */
		if( f->ball1+f->ball2==10 )
			f->b2 = '/';			/* a spare */
		else
			f->b2 = f->ball2 ? f->ball2+'0' : '-';
		f->score = f->ball1+f->ball2;
	}
}

int main()
{
	struct frame game;

	/* initialize the randomizer */
	srand( (unsigned)time(NULL) );

	/* play a frame */
	fill_frame(&game);
	/* output results */
	printf("| %c|%c|\n",game.b1,game.b2);
	printf("|%3d |\n",game.score);

	return(0);
}

/* One flaw with this emulation is that downing 9 pins
   pretty much always results in a spare. This is due
   to the code's math, where it's easier to generate a
   1 or 0 than it is to knock down the last pin in a
   bowling alley. You can add code that weights the
   second ball as more difficult, such as using 10
   as the argument for the ball_roll() function, and
   then using a value only if its less than the pins
   remaining. This is one approach to more accurately
   simulating a bowling frame */
