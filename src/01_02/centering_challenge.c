#include <stdio.h>

void center_text(int width, char *text)
{
	int len = strlen(text);
	double pre = (width - len)/2;
	if(pre<0) pre=0;

	//printf("len=%d, diff=%f, pre=%d\n", len, diff, pre);

	for(int i=0; i<pre; i++)
		printf(" ");
	printf(text);
	printf("\n");
}

int main()
{
	/* some sample text to center */
	char *title[] = {
			"March Sales",
			"My First Project",
			"Centering output is so much fun!",
			"This title is very long, just to see whether the code can handle such a long title"};
	int x;

	/* output each of the strings, centered */
	for (x = 0; x < 4; x++)
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x]);
	}

	return (0);
}
