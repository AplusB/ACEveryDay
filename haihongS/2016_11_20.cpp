#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const ll inf=1e9;
const ll mod=1e9+7;
const double eps=1e-9;

ll gg(ll x);
vector<ll> ans;

int main()
{
	ll a,b,c;
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		ans.clear();
		int cnt=0;
		for(ll i=1;i<81;i++)
		{
			ll now=1;
			for(int j=0;j<a;j++)
			{
				now=now*i;
				if(now>=inf) break;
			}
			if(now>=inf) continue;
			ll x=b*now+c;
			if(x>=inf) continue;
			if(gg(x)==i) cnt++,ans.push_back(x);
		}
		printf("%d\n",cnt);
		for(int i=0;i<ans.size();i++)
		{
			if(i!=0) printf(" ");
			printf("%lld",ans[i]);
		}
		if(cnt>0) printf("\n");
	}
	return 0;
}

ll gg(ll x)
{
	ll v=0;
	while(x)
	{
		v+=x%10;
		x/=10;
	}
	return v;
}
