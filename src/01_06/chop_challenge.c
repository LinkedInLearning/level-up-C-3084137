#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
	int i;
	char *hey;
	hey=malloc(sizeof(char)*len+1);
	for(i=0;i<len;i++)
	{
		*(hey+i)=*(s+i);
	}
	*(hey+i)='\0';
	return(hey);
}

char *right(char *s,int len)
{
	int z,y=len;
	char *yes;
	yes=malloc(sizeof(char)*len+1);
	for(z=0;z<=len;z++,y++)
	{
		*(yes+z)=*(s+y);
	}
	*(yes+z)='\0';
	return(yes);
	
}

char *mid(char *s,int offset, int len)
{
	int q,w;
	char *mam;
	mam=malloc(sizeof(char)*len+1);
	for(q=0;q<=len;q++)
	{
		*(mam+q)=*(s+offset+q);
		if(*(mam+q)=='\0')
		break;
	}
	*(mam+q)='\0';
	return(mam);
}

int main()
{
	char string[] = "Once_upon_a_time,_there_was_a_string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,12,11));

	return(0);
}