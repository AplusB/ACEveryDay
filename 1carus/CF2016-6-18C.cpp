#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

typedef pair<ll,ll> P;
vector<P> g[MAXN];
ll son[MAXN],a[MAXN];
ll n,ans;

void dfs1(ll cur,ll pre)
{
	son[cur] = 1;
	int i;
	for(i = 0;i < g[cur].size();i++)
	{
		ll u = g[cur][i].first;
		if(u != pre)
		{
			dfs1(u,cur);
			son[cur] += son[u];
		}
	}
}

void dfs2(ll cur,ll pre,ll vis)
{
	if(vis > a[cur])
	{
		ans += son[cur];
		return ;
	} 
	
	int i;
	for(i = 0;i < g[cur].size();i++)
	{
		ll u = g[cur][i].first;
		if(u != pre)
		{
			dfs2(u,cur,max(vis + g[cur][i].second,g[cur][i].second));
		}
	}
}

int main()
{
 	scanf("%lld",&n);
 	
 	ans = 0;
 	int i;
 	for(i = 1;i <= n;i++)
 	{
 		scanf("%lld",&a[i]);
	}
	
	ll u,val;
	for(i = 2;i <= n;i++)
	{
		scanf("%lld %lld",&u,&val);
		g[i].push_back(P(u,val));
		g[u].push_back(P(i,val));
	}
	
	dfs1(1,-1);
	dfs2(1,-1,-0x3f3f3f3f);
	cout << ans << endl;
	
	return 0;
}
