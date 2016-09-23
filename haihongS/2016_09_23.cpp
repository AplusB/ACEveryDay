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
const int maxn=2000+200;
const double eps=1e-9;
const int inf=2e9+9;

struct edge
{
	int to,cap,rev;
};


vector<edge> G[maxn];
int level[maxn],iter[maxn];

typedef pair<int,int> P;
struct II
{
	int to,w,cost;
};
vector<II> B[maxn];
int dist[maxn][2];


void add(int from,int to,int w,int cost);
void Dijkstra(int s,int ff);

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
			B[i].clear();
		}
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,1,w);
			add(v,u,1,w);
		}
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<2;j++)
				dist[i][j]=inf;
		}
		Dijkstra(1,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<B[i].size();j++)
			{
				II nx=B[i][j];
				if(dist[i][0]+1==dist[nx.to][0])
				{
					add_edge(i,nx.to,nx.cost);
				}
			}
		}
		printf("%d\n",max_flow(1,n));

	}

	return 0;
}

void Dijkstra(int s,int ff)
{
	dist[s][ff]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	while(!q.empty()) q.pop();
	q.push(P(0,s));
	while(!q.empty())
	{
		P tp=q.top();q.pop();
		int v=tp.second;
		if(dist[v][ff]<tp.first) continue;
		for(int i=0;i<B[v].size();i++)
		{
			II nx=B[v][i];
			int node=nx.to;
			if(dist[node][ff]>dist[v][ff]+nx.w)
			{
				dist[node][ff]=dist[v][ff]+nx.w;
				q.push(P(dist[node][ff],node));
			}

		}
	}
}

void add(int from,int to,int w,int cost)
{
	II now;
	now.to=to,now.w=w,now.cost=cost;
	B[from].push_back(now);
}

int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,inf))>0)
			flow+=f;
	}
}

int dfs(int v,int t,int f)
{
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to])
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++)
		{
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0)
			{
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}


