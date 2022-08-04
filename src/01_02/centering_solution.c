#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	int len,indent,s;

	len = strlen(text);
	indent = (width-len)/2;
	for( s=0; s<indent; s++ )
		putchar(' ');
	printf("%s\n",text);
}

int main()
{
	char *title[] = {
	   "March Sales",
	   "My First Project",
	   "Centering output is so much fun!",
	   "This title is very long, just to see whether the code can handle such a long title"
	};
	int x;

	for( x=0; x<4; x++ )
	{
		center_text( 80, title[x] );
	}

	return(0);
}
