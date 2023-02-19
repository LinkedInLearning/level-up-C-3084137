#include<stdio.h>
void main()
{
  int qua=0,dim=0,nic=0,pen=0,i=1;
  float amount[] = {
      0.49, 1.27, 0.75, 1.31, 0.83};
  for(i;i<5;i++)
  {
    qua=dim=nic=pen=0;
    amount[i]=amount[i]*100;
   while(amount[i]>=25)
   {
    qua++;
    amount[i]-=25;
   }
   while (amount[i] >= 10)
   {
    dim++;
    amount[i]-=10;
   }
   while (amount[i] >= 5)
   {
    nic++;
    amount[i]-=5;
   }
   while (amount[i]>=1)
   {
    pen++;
    amount[i]-=1;
   }
   printf("\n Changes are Quater=%d\tDime=%d\tnickel=%d\tpenny=%d", qua, dim, nic, pen);
   printf("\n");
  }


}