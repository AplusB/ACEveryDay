#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const ll inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

vector<ll> u,p;

int main()
{
	ll a,b,c;
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		u.clear();
		p.clear();
		ll m;
		scanf("%lld",&m);
		for(int i=0;i<m;i++)
		{
			ll v;
			char name[20];
			scanf("%lld %s",&v,name);
			if(name[0]=='U') u.push_back(v);
			else p.push_back(v);
		}
		sort(u.begin(),u.end());
		sort(p.begin(),p.end());
		int ulen=u.size(),plen=p.size();
		int upos=0,ppos=0;
		ll cnt=0,ans=0;
		while(upos<ulen && a>0)
		{
			cnt++;
			ans+=u[upos++];
			a--;
		}
		while(ppos<plen && b>0)
		{
			cnt++;
			ans+=p[ppos++];
			b--;
		}
		while(c>0 && (upos<ulen || ppos<plen))
		{
			if(upos==ulen)
			{
				cnt++,c--;
				ans+=p[ppos++];
				continue;
			}
			if(ppos==plen)
			{
				cnt++,c--;
				ans+=u[upos++];
				continue;
			}
			if(u[upos]<=p[ppos])
			{
				cnt++,c--;
				ans+=u[upos++];
			}
			else
			{
				cnt++,c--;
				ans+=p[ppos++];
			}
		}
		printf("%lld %lld\n",cnt,ans);
	}
	return 0;
}
