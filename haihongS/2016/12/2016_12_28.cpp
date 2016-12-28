#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e4+60;
const ll inf=2e9+9;

vector<int> G[maxn];
int biao[maxn],deep[maxn],ans[maxn];

void comp(int v,int fa,int bb);
void dfs(int v,int fa,int dep);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			biao[i]=0;
		}
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int uu=1;
		for(int i=1;i<=n;i++)
		{
			if(biao[i]==0)
				comp(i,i,uu++);
		}
		if(uu>2)
		{
			printf("Error: %d components\n",uu-1);
			continue;
		}
		dfs(1,1,1);
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			if(deep[i]>maxx)
				maxx=deep[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(deep[i]==maxx)
				ans[cnt++]=i;
		}
		dfs(ans[0],ans[0],1);
		maxx=-1;
		for(int i=1;i<=n;i++)
			maxx=max(deep[i],maxx);
		for(int i=1;i<=n;i++)
		{
			if(deep[i]==maxx)
				ans[cnt++]=i;
		}
		sort(ans,ans+cnt);
		int len=unique(ans,ans+cnt)-ans;
		for(int i=0;i<len;i++)
		{
			printf("%d\n",ans[i]);
		}


	}
	return 0;
}

void dfs(int v,int fa,int dep)
{
	deep[v]=dep;
	int len=G[v].size();
	for(int i=0;i<len;i++)
	{
		int nx=G[v][i];
		if(nx==fa) continue;
		dfs(nx,v,dep+1);
	}
}

void comp(int v,int fa,int bb)
{
	int len=G[v].size();
	for(int i=0;i<len;i++)
	{
		int nx=G[v][i];
		if(nx==fa) continue;
		if(biao[nx]!=0) continue;
		biao[nx]=bb;
		comp(nx,v,bb);
	}
}
