#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define RSIZE 15

int main()
{
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	int frequency[PSIZE];
	int recent[RSIZE];		/* holds recently-played songs */
	int x,r,count,found;

	/* initialize */
	srand( (unsigned)time(NULL) );
	for(x=0;x<PSIZE;x++)
		frequency[x] = 0;
	for(x=0;x<RSIZE;x++)
		recent[x] = -1;			/* -1 because no element is -1 */


	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while(count<100)
	{
		/* does r appear in the recent[] list? */
		found = 1;				/* assume it does */
		while(found)
		{
			r = rand() % PSIZE;		/* random song from the list */
			found = 0;				/* not found yet */
			/* see if the song was recently-played */
			for(x=0;x<RSIZE;x++)
			{
				if( r==recent[x] )
					found=1;		/* found! */
			}
			/* found==0 here if the song isn't in the
			   recently-played list */
		}
		/* add the song to the recently-played list */
		recent[count%RSIZE] = r;		
		/* play the song */
		printf("%3d: Now Playing '%s'\n",
				count+1,
				playlist[r]
			  );
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for(x=0;x<PSIZE;x++)
		printf("%s: %d\n",playlist[x],frequency[x]);

	return(0);
}
