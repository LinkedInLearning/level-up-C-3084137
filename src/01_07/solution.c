#include<stdio.h>
int leapyear(int y)
{
    if(y%400==0)
    return(1);
    if(y%100==0)
    return(0);
    if(y%4==0)
    return(1);
    return(0);
}
void main()
{
    int i;
    for(i=1528;i<=2101;i++)
    {
        if(leapyear(i)==1)
        printf("%d \n",i);
    }
}