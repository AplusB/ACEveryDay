#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int n,k;
int flag[maxn],num[maxn];
vector<int> G[maxn];

int dfs(int node,int fa);


int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			flag[i]=0,num[i]=0;
		}
		for(int i=0;i<2*k;i++)
		{
			int x;
			scanf("%d",&x);
			flag[x]=1;
		}
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,1);
		ll ans=0;
		for(int i=2;i<=n;i++)
		{
			int tmp=min(num[i],2*k-num[i]);
			//printf("--%d %d\n",i,tmp);
			ans+=(ll)tmp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


int dfs(int node,int fa)
{
	int cnt=flag[node];
	for(int i=0;i<G[node].size();i++)
	{
		int v=G[node][i];
		if(v==fa) continue;
		cnt+=dfs(v,node);
	}
	num[node]=cnt;
	return cnt;
}
