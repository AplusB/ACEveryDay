//单源最短路Dijkstra
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=100000+5;//最大的点数量为100000
const int inf=0x7fffffff;
int vis[N],dis[N],path[N],n,m;
struct Edge
{
	int  to,w;
};

vector<Edge>edges;
vector<int>G[N];
void AddEdge(int u,int v,int w)
{
	Edge t;
	t.to=v;t.w=w;
	edges.push_back(t);
	t.to=u;
	edges.push_back(t);
	int g=edges.size();
    G[u].push_back(g-2);
    G[v].push_back(g-1);
}

void Dijkstra(int st)
{
	int u,v,w,minw;
	for(int i=0;i<n;i++)
	{
		dis[i]=inf;
		vis[i]=0;
		path[i]=-1;
	}
	vis[st]=0;
	dis[st]=0;
	for(int i=0;i<n;i++)
	{
		minw=inf;
		u=-1;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&dis[j]<minw)
			{
				minw=dis[j];
				u=j;
			}
		}
		if(minw==inf) break;
		vis[u]=1;
		for(int k=0;k<G[u].size();k++)
		{
			v=edges[G[u][k]].to;
			w=edges[G[u][k]].w;
			if(!vis[v]&&dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				path[v]=u;
			}
		}
	}
}

int main()
{
	int st,ed,u,v,w;
	while(~scanf("%d%d",&n,&m))
	{
	//n个点，m条边,点从0开始编号
	//scanf("%d",&st);//起点st
	edges.clear();
	for(int i=0;i<N;i++)
		G[i].clear();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);//u和v之间有一条权值为w的无向边
		AddEdge(u,v,w);
	}
	scanf("%d%d",&st,&ed);
	Dijkstra(st);
	if(dis[ed]==inf) printf("-1\n");
	else printf("%d\n",dis[ed]);
	}
	return 0;
}
