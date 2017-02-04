#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

int main()
{
	ll x,y;
	while(~scanf("%lld%lld",&x,&y))
	{
		ll ans=0;
		for(ll i=1;i<=x;i++)
		{
			ll lt=ceil(1.0*(1+i)/5);
			lt=max(1LL,lt);
			ll rt=floor(1.0*(i+y)/5);
			ans+=rt-lt+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
