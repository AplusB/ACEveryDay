#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const double inf=2e9;
const double eps=1e-12;

ll a[maxn],pp[100];
map<ll,int> aha;

int main()
{
	pp[0]=1;
	for(int i=1;i<=35;i++)
		pp[i]=1LL*2*pp[i-1];
	int n;
	while(~scanf("%d",&n))
	{
		aha.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=35;j++)
			{
				ll now=pp[j]-a[i];
				if(now<0) continue;
				ans+=aha[now];
			}
			aha[a[i]]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
