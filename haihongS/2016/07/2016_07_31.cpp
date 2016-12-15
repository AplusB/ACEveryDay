#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn=3e5+9;
const int inf=2e9+9;

vector<int> G[maxn];
int fa[maxn],son[maxn],cen[maxn],sub[maxn];

int dfs(int node);
int findit(int node);

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			fa[i]=i;
			cen[i]=-1;
			sub[i]=0;
		}
		for(int i=2;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			fa[i]=x;
			G[x].push_back(i);
		}
		dfs(1);
		findit(1);
		while(q--)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",cen[x]);
		}

	}
	return 0;
}


int findit(int node)
{
	if(G[node].size()==0)
	{
		cen[node]=node;
		return 0;
	}
	int loca=G[node][0];
	for(int i=0;i<G[node].size();i++)
	{
		int x=G[node][i];
		findit(x);
		if(son[x]>son[loca])
			loca=x;
	}
	int pri=cen[loca];
	while(pri!=node)
	{
		if(sub[pri]*2<=son[node]+1 && 2*(son[node]-son[pri])<=son[node]+1)
			break;
		pri=fa[pri];
	}
	cen[node]=pri;
	return 0;
}

int dfs(int node)
{
	int cnt=0;
	for(int i=0;i<G[node].size();i++)
	{
		int x=G[node][i];
		int tmp=dfs(x);
		sub[node]=max(sub[node],tmp);
		cnt+=tmp;
	}
	son[node]=cnt;
	return cnt+1;
}
