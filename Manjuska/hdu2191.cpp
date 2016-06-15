#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int money,type;
int price[105],weigh[105],num[105],dp[105];
int max(int a,int b)
{
     return a>b?a:b;
}
void CompletePack(int price,int weigh)
{
     for(int i=price;i<=money;i++)
         dp[i]=max(dp[i],dp[i-price]+weigh);
}
void ZeroOnePack(int price,int weigh)
{
     for(int i=money;i>=price;i--)
         dp[i]=max(dp[i],dp[i-price]+weigh);
}
void MultiplePack(int price,int weigh,int num)
{
     if(price*num>=money)
          CompletePack(price,weigh);
     int k=1;
     while(k<num)
     {
          ZeroOnePack(k*price,k*weigh);
          num-=k;
          k>>1;
     }
     ZeroOnePack(num*price,num*weigh);
}
int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d %d",&money,&type);
          memset(dp,0,sizeof(dp));
          for(int i=1;i<=type;i++)
          {
               scanf("%d %d %d",&price[i],&weigh[i],&num[i]);
               MultiplePack(price[i],weigh[i],num[i]);
          }
          printf("%d\n",dp[money]);
     }
     return 0;
}
