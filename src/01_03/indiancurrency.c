#include<stdio.h>
#include<stdlib.h>

void main()
{
  int *p,n;
  int a[5];
  int a2000,a500,a200,a100,a50,a20,a10,a5,a2,a1;
  printf("Enter no. of Value you are going to enter at a time");
  scanf("%d",&n);

  
  for(int i=0;i<=n;i++)
  {  printf("\nEnter your value");
    scanf("%d",&a[i]);
    a2000= a500= a200= a100= a50= a20= a10= a5= a2= a1=0;
     printf("\n Change for %d\n", a[i]);
     printf("\t2000\t500\t200\t100\t50\t20\t10\t5\t2\t1\t\n");
  
    while(a[i]>=2000)
    {
      a2000++;
      a[i]-=2000;
    }
    while(a[i]>=500)
    {
      a500++;
      a[i]-=500;
    }
    while(a[i]>=200)
    {
      a200++;
      a[i]-=200;
    }
    while(a[i]>=100)
    {
      a100++;
      a[i]-=100;
    }
    while(a[i]>=50)
    {
      a50++;
      a[i]-=50;
    }
    while(a[i]>=20)
    {
      a20++;
      a[i]-=20;
    }
    while(a[i]>=10)
    {
      a10++;
      a[i]-=10;
    }
    while(a[i]>=5)
    {
      a5++;
      a[i]-=5;
    }
    while(a[i]>=2)
    {
      a2++;
      a[i]-=2;
    }
    while(a[i]>=1)
    {
      a1++;
      a[i]-=1;
    }
  printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",a2000,a500,a200,a100,a50,a20,a10,a5,a2,a1);

  }
}