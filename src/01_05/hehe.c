#include<stdio.h>
void main()
{
    float i=1;
    while(1)
    {
       float j=0.2345629490238;
        i++;;
        printf("\nN\t %f ",j);
        printf("\n2\t %2.2f ",j);
        printf("\n6\t %6f ",j);
        printf("\n6.2\t %6.2f ",j);
        printf("\n8\t %8f ",j);
        if(i==7)
        break;
    }
    getchar();
}