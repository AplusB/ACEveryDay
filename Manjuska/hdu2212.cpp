#include"stdio.h"
int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
int i,t,temp;
    int sum;
for(i=1;i<=9999999;i++)
       {sum=0;
       int n=i;
        while(n)
         {
        t=n%10;
    sum+=a[t];
    n=n/10;
     }      
      if(sum==i)
printf("%d\n",i);

      }
return 0;
}

