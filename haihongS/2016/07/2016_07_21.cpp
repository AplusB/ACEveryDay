#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=2e9+9;

struct II
{
	int from,to,cost;
}edge[maxn*10];

struct PP
{
	int to,cost;
};

vector<PP> G[maxn];
int fa[maxn],cc[maxn],n,m;
double ans;

int add_edge(int u,int v,int w);
int find(int x);
int cmp(II x,II y);
int dfs(int node,int ff);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			fa[i]=i,cc[i]=1;
		}
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			edge[i].from=u,edge[i].to=v,edge[i].cost=w;
		}
		sort(edge+1,edge+1+m,cmp);
		ll res=0;
		int pt=0;
		for(int i=1;i<=m;i++)
		{
			if(pt==n-1) break;
			int fu=find(edge[i].from),fv=find(edge[i].to);
			if(fu!=fv)
			{
				pt++;
				add_edge(edge[i].from,edge[i].to,edge[i].cost);

				fa[fu]=fv;
				res+=(ll)edge[i].cost;
			}
		}
		ans=0;
		dfs(1,1);
		double go=2.0*ans/(n)/(n-1);
		printf("%lld %.2lf\n",res,go);
	}
	return 0;
}

int dfs(int node,int ff)
{
	int mm=1;
	for(int i=0;i<G[node].size();i++)
	{
		int v=G[node][i].to;
		if(v==ff) continue;
		int tmp=dfs(v,node);
		mm+=tmp;
		ans+=1.0*tmp*(n-tmp)*G[node][i].cost;
	}
	return mm;
}

int cmp(II x,II y)
{
	return x.cost<y.cost;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int add_edge(int u,int v,int w)
{
	PP tmp;
	tmp.to=v,tmp.cost=w; G[u].push_back(tmp);
	tmp.to=u; G[v].push_back(tmp);
	return 0;
}
