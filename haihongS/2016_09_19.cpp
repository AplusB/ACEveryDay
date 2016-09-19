#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>



using namespace std;

typedef long long ll;
const ll mod=1e9+7;

const int N = 1000005;

ll fac[N];

void init()//预处理阶乘
{
    fac[0]=1;
    for(int i=1;i<=N;i++)
        fac[i]=i*fac[i-1]%mod;
}
ll pow_mod(ll a,ll b)
{
    ll s=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
            s=s*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return s;
}
ll C(int n,int m)
{
    if(m>n)
        return 0;
    return  fac[n]*pow_mod(fac[m]*fac[n-m]%mod,mod-2)%mod;
}
ll Lucas(int n,int m)
{
    if(m==0)
        return 1;
    return C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod;
}
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
//*********求逆元素*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll now=n-1-m*k;
        ll ans=Lucas(now,m-1);
        ll ni=mod_reverse(m,mod);
        ans=(ans*n)%mod;
        ans*=ni;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}
