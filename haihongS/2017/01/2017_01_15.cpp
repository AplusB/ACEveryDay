#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e3+9;
const int inf=2e9+9;
const ll mod=1e9+7;
double eps=1e-6;
double pi=acos(-1.0);

int a[maxn],n;
ll m,sum;
ll jie[maxn],rev[maxn];
ll aha[2*maxn];

void init();
ll C(ll x,ll y);
long long extend_gcd(long long a,long long b,long long &x,long long &y);
long long mod_reverse(long long a,long long n);


int main()
{
	freopen("ok.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();

	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=2LL*a[i];
		}
		for(int i=0;i<=4000;i++)
		{
			ll x=m-1;
			x-=sum-1LL*i;
			aha[i]=C(x+1LL*n,1LL*n);
		}

		printf("Case #%d: ",cas++);
		if(n==1)
		{
			printf("%lld\n",m);
			continue;
		}

		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				/*
				ll now=0;
				ll x=m-1;
				x=x-(sum-a[i]-a[j]);
				now=C(x+1LL*n,1LL*n);
				*/
				//printf("*%d\n",a[i]+a[j]);
				ll now=aha[a[i]+a[j]];
				ans=(ans+now)%mod;
			}
		}
		ans=(ans*2)%mod;
		ans=(ans*jie[n-2])%mod;

		printf("%lld\n",ans);
	}
	return 0;
}

ll C(ll x,ll y)
{
	if(y>x) return 0;
	if(x==y) return 1;
	ll ans=1;
	for(ll i=1;i<=y;i++)
	{
		ans*=x-y+i;
		ans%=mod;
	}
	ans*=rev[y];
	ans%=mod;
	return ans;
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

void init()
{
	jie[0]=1;
	for(ll i=1;i<3000LL;i++)
	{
		jie[i]=(jie[i-1]*i)%mod;
		rev[i]=mod_reverse(jie[i],mod);
	}
}
