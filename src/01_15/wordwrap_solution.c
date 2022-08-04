#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

/* output a line of text, s to e */
void writeline(char *s, char *e)
{
	do
	{
		if( *s=='\0' )		/* avoid reading beyond the end */
			return;
		putchar(*s);
		s++;
	}
	while(s<=e);
}

int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";
	char *start,*end;
	int width;

	/* check for an argument and set width*/
	width = W_DEFAULT;
	if( argc>1 )
	{
		width = strtol(argv[1],NULL,10);
		/* check the limits */
		if( width<W_MIN || width>W_MAX )
			width=W_DEFAULT;		/* use default width */
	}

	/* wrap the text to 'width' */
	start = end = text;				/* initialize all the pointers */
	while( *end )					/* loop until the end of text */
	{
		/* check for newline and wrap */
		if( *end=='\n')
		{
			writeline(start,end);	/* output line so far */
			end++;					/* skip over the newline */
			start = end;			/* reset pointers */
		}
		else
		{
			end++;					/* advance through text */
			/* are we ready to wrap? */
			if( end==start+width )
			{
				/* look backwards until a space is found */
				while( !isspace(*end) )
				{
					end--;
					/* watch for overflow */
					if( start==end )
					{
						end+=width;		/* output the line anyway */
						break;
					}
				}
				writeline(start,end);
				if( *end != '\n')		/* if the buffer lacks a newline */
					putchar('\n');		/* append a newline */
				end++;					/* prepare end for next line */
				start = end;			/* initialize start */
			}
		}
	}
	writeline(start,end);			/* a final flush of the buffer */
	if( *end != '\n')				/* check for newline */
		putchar('\n');

	return(0);
}
