#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=20+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

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
	freopen("mm.in","r",stdin);
	freopen("mm.out","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		ll n,m;
		scanf("%lld %lld",&n,&m);
		printf("Case #%d: ",cas++);
		ll ans=0,x=min(n,m);
		ll n2=mod_reverse(2,mod);
		ll n6=mod_reverse(6,mod);
		ll n4=mod_reverse(4,mod);

		ll tmp=n*m%mod*(x+1)%mod*x%mod*n2%mod;
		ans+=tmp;
		tmp=(n+m)%mod*x%mod*(x+1)%mod*(2*x+1)%mod*n6%mod;
		tmp=-tmp;
		ans+=tmp;
		tmp=x*x%mod*(x+1)%mod*(x+1)%mod*n4%mod;
		ans+=tmp;
		ans=(ans%mod+mod)%mod;

		printf("%lld\n",ans);

	}
	return 0;
}
