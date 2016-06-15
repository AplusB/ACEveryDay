#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 1000100
#define MOD 100000007

using namespace std;

typedef long long int LL;

LL n,m;
LL power[MAXN]; //power[i]=2^i
LL g[MAXN],f[MAXN],ans; //f[i]=前i段合法的方案数，g[i]=A(2^n-1,i)

LL fastPow(LL base,LL pow)
{
    LL ans=1;
    while(pow)
    {
        if(pow&1) ans=ans*base%MOD;
        base=base*base%MOD;
        pow>>=1;
    }
    return ans;
}

LL extGCD(LL a,LL b,LL &x,LL &y) //ax+by=1
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    LL tmp=extGCD(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-(a/b)*y;
    return tmp;
}

LL reverse(LL a,LL b) //求模b意义下a的逆元x,ax=1(mod b),b是质数所以可以求逆元(gcd(a,b)=1)
{
    LL x,y;
    extGCD(a,b,x,y);
    x=(x%b+b)%b;
    return x;
}

void init()
{
    LL i,a=fastPow(2,n)-1;
    g[0]=1;
    for(i=1;i<=m;i++) g[i]=g[i-1]*(a-i+1)%MOD;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    init();
    LL a=fastPow(2,n)-1,i;
    f[1]=f[2]=0;
    for(i=3;i<=m;i++)
    {
        f[i]=g[i-1]-f[i-1]-f[i-2]*(i-1)%MOD*(a-(i-2))%MOD;
        f[i]%=MOD;
    }
    if(f[m]<0) f[m]+=MOD;
    a=1;
    for(i=1;i<=m;i++) a=a*i%MOD;
    a=reverse(a,MOD);
    f[m]=f[m]*a%MOD;
    printf("%lld\n",f[m]);
    return 0;
}
