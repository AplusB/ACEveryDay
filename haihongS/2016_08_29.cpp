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

using namespace std;
typedef long long ll;
const int maxn=5e4+9;

vector<int> G[maxn];
vector<int> rG[maxn];
int flag[maxn],cnt,used[maxn],topo[maxn];

int add_edge(int u,int v);
int dfs(int node,int fa);
int rdfs(int node,int fa,int k);

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			rG[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			add_edge(u,v);
		}
		cnt=0;
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)
		{
			if(used[i]==0)
				dfs(i,i);
		}
		memset(used,0,sizeof(used));
		int num=0;
		for(int i=cnt-1;i>=0;i--)
		{
			if(used[flag[i]]==0)
				rdfs(flag[i],flag[i],num++);//printf("*%d\n",flag[i]);
		}
		//for(int i=0;i<n;i++)
		//	printf("**%d\n",topo[i]);
		int ans=0,go=0;
		for(int i=0;i<n;i++)
		{
			if(topo[i]==num-1)
			{
				ans++;
				go=i;
			}
		}
		memset(used,0,sizeof(used));
		rdfs(go,go,1);
		for(int i=0;i<n;i++)
			if(used[i]==0)
			{
				ans=0;break;
			}
		printf("%d\n",ans);

	}

	return 0;
}


int rdfs(int node,int fa,int k)
{
	int len=rG[node].size();
	topo[node]=k;
	used[node]=1;
	for(int i=0;i<len;i++)
	{
		int nx=rG[node][i];
		if(nx==fa) continue;
		if(used[nx]==1) continue;
		rdfs(nx,node,k);
	}
	return 0;
}

int dfs(int node,int fa)
{
	int len=G[node].size();
	used[node]=1;
	for(int i=0;i<len;i++)
	{
		int nx=G[node][i];
		if(nx==fa) continue;
		if(used[nx]==1) continue;
		dfs(nx,node);
	}
	//printf("*%d %d\n",node,cnt);
	flag[cnt++]=node;
	return 0;
}

int add_edge(int u,int v)
{
	G[u].push_back(v);
	rG[v].push_back(u);
	return 0;
}
