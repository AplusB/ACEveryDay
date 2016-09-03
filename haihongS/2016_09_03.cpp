#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const double eps=1e-9;
const ll inf=1e13+9;
const ll mod=1e6+3;

ll quick_pow(ll a,ll b);
ll ext_gcd(ll a,ll b,ll &x,ll &y);

int main()
{
	ll n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		int ff=0;
		ll di=1;
		for(ll i=1;i<=n;i++)
		{
			di*=2;
			if(di>=m)
			{
				ff=1;break;
			}
		}
		if(ff==0)
		{
			printf("1 1\n");continue;
		}
		ll zhi=0;
		for(ll i=2;(m-1)/i>0;i*=2)
		{
			zhi+=(m-1)/i;
		}
		ll x,y;
		ll a=quick_pow(2LL,zhi);
		ll rev=ext_gcd(a,mod,x,y);
		rev=x/rev;
		rev=(rev%mod+mod)%mod;
		ll up=1,down=1;
		
		ll phi=mod-1;
		ll go=((n%phi)*(((m-1)%phi+phi)%phi));
		go=((go%phi)+phi)%phi;
		down=quick_pow(2LL,go);
		down=(down*rev)%mod;

		if(m-1>=mod)
			up=0;
		else
		{
			for(ll i=1;i<=m-1;i++)
			{
				up*=quick_pow(2LL,n)-i+mod;
				up%=mod;
			}
			up=(up*rev)%mod;
		}

		up=(down-up+mod)%mod;
		printf("%lld %lld\n",up,down);

	}
	return 0;
}

ll ext_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll ans=ext_gcd(b,a%b,x,y);
	ll t=x;x=y;y=t-(a/b)*y;
	return ans;
}

ll quick_pow(ll a,ll b)
{
	ll ans=1,tmp=a;
	while(b)
	{
		if(b&1)
			ans*=tmp;
		ans%=mod;
		tmp*=tmp;
		tmp%=mod;
		b>>=1;
	}
	return ans;
}
