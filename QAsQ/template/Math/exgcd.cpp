#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long

LL extend_gcd(LL a,LL b,LL &x,LL &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    LL d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

