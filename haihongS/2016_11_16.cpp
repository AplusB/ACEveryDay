#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

struct II
{
	int id;
	ll v;
	friend bool operator<(const II x,const II y)
	{
		ll xx=(x.v/10+1)*10-x.v;
		ll yy=(y.v/10+1)*10-y.v;
		// big
		return xx>yy;
	}
}a[maxn];

priority_queue<II> aha;


int main()
{
	int n;
	ll m;
	while(~scanf("%d%lld",&n,&m))
	{
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i].v);
			a[i].id=i;
		}
		while(!aha.empty()) aha.pop();
		for(int i=0;i<n;i++)
			aha.push(a[i]);
		while(m>0 && !aha.empty())
		{
			II tp=aha.top();
			aha.pop();
			if(tp.v==100) continue;
			ll del=(tp.v/10+1)*10-tp.v;
			if(del>m) break;
			a[tp.id].v+=del;
			m-=del;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i].v<100 && m>=10)
			{
				ll del=min(100-a[i].v,m/10*10);
				a[i].v+=del;
				m-=del;
			}
			ans+=a[i].v/10;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
