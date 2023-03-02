#include<stdio.h>
#include<time.h>
#include<stdlib.h>
struct time {
     int rows;
     int colm;
     char *cells;
};
void output(struct time g)
{    
   
     int r,c;
     for(r=0;r<g.rows;r++)
     {     for(c=0;c<g.colm;c++)
              { printf("%c ",*(g.cells+(g.colm*r)+c));
              }
              printf("\n");
     }
}

void rotated( struct time *g)
{
     struct time *r;
     int rsize,i,j,p=0;

     r=(struct time *)malloc(sizeof(struct time));
     r->rows=g->colm;
     r->colm=g->rows;
     rsize=r->colm*r->rows;

     if(r==NULL)
     {
          printf("\nError Occured");
     }

     r->cells=(char *)malloc(sizeof(char)*rsize);

     for(i=0;i<g->colm;i++)
     {
          for(j=g->rows-1;j>=0;j--)
          {
               *(r->cells+p)=*(g->cells+(g->colm*j)+i);
               
               p++;
          }
     }
     for(i=0;i<rsize;i++)
     {
          *(g->cells+i)=*(r->cells+i);
     }
     g->colm=r->colm;
     g->rows=r->rows;
  free(r->cells);
     free(r);
   
     
}



void input(struct time g)
{
     int r,c;
     for(r=0;r<g.rows;r++)
          for(c=0;c<g.colm;c++)
               *(g.cells+(g.colm*r)+c) = rand()%26+'a';
}

void main()
{

struct time grid[4]={{2,5,NULL},{4,4,NULL},{8,3,NULL},{8,5,NULL}};
int a,b;
srand((unsigned)time(0));
for(a=0;a<3;a++)
{
         grid[a].cells=(char *)malloc(sizeof(char)*grid[a].colm*grid[a].rows);
}

for(a=0;a<3;a++)
     {
      
          input(grid[a]);
          printf("Original Matrix : \t\n\n");
          output(grid[a]);
          printf("\nRotated Matrix :\n\n");
          rotated(&grid[a]);
          output(grid[a]);

     }
     getchar();
}