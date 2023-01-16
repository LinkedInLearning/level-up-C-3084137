#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define RECENT 15

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
			"A Change Is Gonna Come"};
	int frequency[PSIZE];
	int recent[RECENT];
	int i, x, r, count;

	/* initialize */
	srand((unsigned)time(NULL));
	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;
	for (i = 0; i < RECENT; i++)
		recent[i] = 0;

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < 100)
	{
		int ok = 0;
		do
		{											/* does r appear in recent[]? */
			r = rand() % PSIZE; /* random value */
			printf("r: %d  --  ", r);

			// search
			printf("recents: ");
			int flag = 0;
			for (i = 0; i < RECENT; i++)
			{
				printf("%02d, ", recent[i]);
				if (recent[i] == r)
				{
					flag++;
				}
			}
			printf("\n");

			if (flag > 0)
			{
				printf("!!-- REPEAT, RESHUFFLE\n");
				continue;
			}

			ok = 1;

		} while (ok == 0);

		for (i = 0; i < (RECENT - 1); i++)
		{
			recent[i] = recent[i + 1];
		}
		recent[RECENT - 1] = r;

		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[r]);
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}
