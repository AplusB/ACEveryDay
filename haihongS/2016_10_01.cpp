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
const int maxn=5e3+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

struct edge
{
	int to;
	int w;
};

struct II
{
	int cnt,now;
};

int n,m;
int T;
vector<edge> G[maxn];
int dp[maxn][maxn];
int last[maxn][maxn],output[maxn];

void init();
void add_edge(int u,int v,int w);
int deal();

int main()
{
	while(~scanf("%d%d%d",&n,&m,&T))
	{
		init();
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
		}
		deal();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(dp[n][i]<=T)
				ans=i;
		}
		printf("%d\n",ans);
		int ss=n,pos=0;
		output[pos++]=ss;
		while(last[ss][ans]!=-1)
		{
			ss=last[ss][ans];
			ans--;
			output[pos++]=ss;
		}
		for(int i=pos-1;i>=0;i--)
		{
			if(i==pos-1) printf("%d",output[i]);
			else printf(" %d",output[i]);
		}
		printf("\n");

	}
	return 0;
}

int deal()
{
	dp[1][1]=0;
	queue<II> aha;
	while(!aha.empty()) aha.pop();
	II fir;
	fir.cnt=1,fir.now=1;
	aha.push(fir);
	while(!aha.empty())
	{
		II tp=aha.front();aha.pop();
		if(dp[tp.now][tp.cnt]>T) continue;
		for(int i=0;i<G[tp.now].size();i++)
		{
			edge nx=G[tp.now][i];
			int u=tp.now,v=tp.cnt;
			if(dp[u][v]+nx.w<dp[nx.to][v+1])
			{
				dp[nx.to][v+1]=dp[u][v]+nx.w;
				last[nx.to][v+1]=u;
				II go;
				go.cnt=v+1,go.now=nx.to;
				aha.push(go);
			}
		}
	}
	return 0;
}

void init()
{
	for(int i=0;i<maxn;i++) G[i].clear();
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
			dp[i][j]=inf,last[i][j]=-1;
	}
	
}

void add_edge(int u,int v,int w)
{
	edge now;
	now.to=v,now.w=w;
	G[u].push_back(now);
}
