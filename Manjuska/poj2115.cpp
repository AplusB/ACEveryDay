#include<stdio.h>
__int64 f(int k) 
{ 
    __int64 sum=1;
    for(int i=0;i<k;i++)
        sum*=2;
    return sum;
}

__int64 exGcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
   __int64 d,t;
   if(b==0) { x=1; y=0; return a; }
   d=exGcd(b,a%b,x,y);
   t=x; x=y; y=t-a/b*y;
   return d;
}
int main()
{
     __int64 a,b,c,x,y,d,r;
     int k;
     while(scanf("%I64d%I64d%I64d%d",&a,&b,&c,&k))
     {
         if(a==0&&b==0&&c==0&&k==0)
             break;
         d=exGcd(c,f(k),x,y);
         if((b-a)%d!=0) printf("FOREVER\n");
         else{
            x=x*(b-a)/d;
            r=f(k)/d;
            x=(x%r+r)%r;
            printf("%I64d\n",x);
         }
     }
     return 0;
}
