#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define R 7
#define P 15
void main()
{
	char *song[P]={"O RE PIYA", "TUM MERE SANAM", "WHY ARE YOU GAY",
	"MAHABHARAT", "TITAL SOND", "ZINGAAT", "BEGGIN", "BABY", 
	"SATURDAY ", "SHIVBA RAJ", "KRISHNA SONG", "GANPATI SONG", "RAP SONG",
	"I WANNA BE YOUR SLAVE", "BREATHLESS"};

	char repeat[R]; // This is to song must'n repeat until next 7 song (R)

	int play,count,x;
	srand((unsigned)time(0)); // To make every time random song 
	for(x=0;x<R;x++)
	repeat[x]=-1;			// (R) -1 mean NULL
	int r,frequency[P],done;
	for(x=0;x<P;x++)
	frequency[x]=0;

	count=0;
	while(count<100)
	{
		done=1;
		while(done)
		{
			done=0;
		r=rand()%P;
		for(x=0;x<R;x++)
		{
		if(r==repeat[x])
		done=1;
		}
		}
		repeat[count%R]=r;		//if done = 1 then that song added to repeat list 
		printf("%d\tNow Playing : %s \n",count+1,song[r]);
		frequency[r]++;

		count++;
		
	}
count=0;
	while(count<P)
	{
		printf("\n%2.2d\t%s\t\t%d",count+1,song[count],frequency[count]);
		count++;
	}
}