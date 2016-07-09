#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=2e9+9;


struct II
{
	ll v,x;
};

map<ll,II> aha;

II dfs(ll node);
ll bi(ll x);

int main()
{
	ll m;
	while(~scanf("%lld",&m))
	{
		aha.clear();
		II ans=dfs(m);
		printf("%lld %lld\n",ans.v,ans.x);
	}
	return 0;
}

II dfs(ll node)
{
	if(aha.find(node)!=aha.end())
		return aha[node];
	if(node==0)
	{
		II s;
		s.v=s.x=0;
		return s;
	}
	ll y1=bi(node);
	ll y2=y1*y1*y1;

	II f1=dfs(y2-1);
	f1.v+=node/y2-1;
	f1.x+=(node/y2-1)*y2;

	II f2=dfs(node%y2);
	f2.v+=node/y2;
	f2.x+=node/y2*y2;

	II ans;
	if(f1.v>f2.v)
		ans=f1;
	else if(f1.v<f2.v)
		ans=f2;
	else
	{
		if(f1.x>f2.x)
			ans=f1;
		else
			ans=f2;
	}
	aha[node]=ans;
	return ans;
}


ll bi(ll x)
{
	ll lt,rt,mid;
	lt=0,rt=maxn;
	ll ans=0;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(mid*mid*mid<=x)
		{
			ans=max(ans,mid);
			lt=mid+1;
		}
		else
			rt=mid-1;
	}
	return ans;
}

