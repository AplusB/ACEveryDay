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
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int a[maxn];
vector<int> G[maxn];
int flag[maxn];
map<int,int> cnt;

int dfs(int v,int fa);

int main()
{
	int n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		// init
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			flag[i]=0;
		}

		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==1) continue;
			cnt.clear();
			flag[i]=1;
			cnt[a[i]]++;
			dfs(i,i);
			int maxx=0;
			map<int,int>::iterator it;
			int all=0;
			for(it=cnt.begin();it!=cnt.end();++it)
			{
				if(it->second>maxx)
					maxx=it->second;
				all+=it->second;
			}
			ans+=all-maxx;
		}
		printf("%d\n",ans);
	}
	return 0;
}

int dfs(int v,int fa)
{
	int len=G[v].size();
	for(int i=0;i<len;i++)
	{
		int nx=G[v][i];
		if(nx==fa) continue;
		if(flag[nx]==1) continue;
		flag[nx]=1;
		cnt[a[nx]]++;
		dfs(nx,v);
	}
	return 0;
}
