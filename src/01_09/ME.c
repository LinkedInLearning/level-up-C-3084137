#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Gsize 8
struct pos{
    int row;
    int col;
};
void changes(int t,struct pos k)
{
    if(t==0)
    printf("Start Position\n");
    else 
    printf("Turn %d\n",t);
int row,col;
for(row=0;row<Gsize;row++)
{
    for(col=0;col<Gsize;col++)
    {
        if((row==k.row)&&(col==k.col))
        printf(" K ");
        else
        printf(" . ");
    }
    printf("\n");
}
}
int move()
{
int j;
j=(rand()%3-1);
return(j);
}
int done(struct pos k)
{
    enum {false,true};
    if(k.row<0)
    return(true);
    if(k.col>=Gsize)
    return(true);
    if(k.col<0)
    return(true);
     if(k.row>=Gsize)
    return(true);
    return(false);
}

void main()
{
    int turn=0;
    struct pos king={4,4};
   srand( (unsigned)time(NULL) );
    while(1)
    {
    
    changes(turn,king);
    
    king.row+=move();
    king.col+=move();
    if(done(king))
    {
    break;
    }
    turn++;
    }
    printf("\nKing turned down after %d turn",turn);
}