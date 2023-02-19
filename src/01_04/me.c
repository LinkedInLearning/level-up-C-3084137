#include<stdio.h>
void main()
{

  int a,i=1;
  printf("ENter no. for hailstone ");
  scanf("%d",&a);
  printf("\n");
  printf("Sequence\t");
  printf("\n");
printf("\t%d",a);
  while(a!=1)
  {
    
    if(a%2==0)
    {
      a=a/2;
      
      i++;
    }
    else
    {
      a=(a*3)+1;
    
      i++;
    }  
    printf("\t%d", a);

  }    if(a==1)
    {
      printf("\t%d",a);
    }
    printf("\n NO. of steps =%d  ",i);
    
   getchar();
}