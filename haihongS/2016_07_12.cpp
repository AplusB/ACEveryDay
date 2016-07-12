#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll ans=0;
		ans=(n+1)*n/2;
		ll tmp=0;
		for(ll i=1;i<=n;i*=2)
		{
			tmp+=2*i;
		}
		ans-=tmp;
		printf("%lld\n",ans);
	}
}
