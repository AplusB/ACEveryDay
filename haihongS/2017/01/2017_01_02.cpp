#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e2+60;
const ll inf=2e9+9;

int n,m,pos,st,ed;
int d[maxn],d2[maxn],ans[maxn];

struct edge
{
	int to,w1,w2;
};

vector<edge> G[maxn];

void add_edge(int u,int v,int w1,int w2);
void Dijkstra(int s);
void deal(int v);

int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&st,&ed))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		pos=0;
		for(int i=0;i<m;i++)
		{
			int u,v,w1,w2;
			scanf("%d%d%d%d",&u,&v,&w1,&w2);
			add_edge(u,v,w1,w2);
			add_edge(v,u,w1,w2);
		}
		Dijkstra(st);
		deal(ed);
		for(int i=pos-1;i>=0;i--)
		{
			if(i!=pos-1) printf(" ");
			printf("%d",ans[i]);
		}
		printf(" %d %d\n",d[ed],d2[ed]);
	}
	return 0;
}

void deal(int v)
{
	ans[pos++]=v;
	if(v==st)	return ;
	int len=G[v].size();
	for(int i=0;i<len;i++)
	{
		edge nx=G[v][i];
		if(d[nx.to]+nx.w1==d[v] && d2[nx.to]+nx.w2==d2[v])
		{
			deal(nx.to);break;
		}
	}
}

void Dijkstra(int s)
{
	for(int i=0;i<n;i++)
		d[i]=inf,d2[i]=inf;
	d[s]=0,d2[s]=0;
	queue<edge> aha;
	while(!aha.empty()) aha.pop();
	aha.push((edge){s,0,0});
	while(!aha.empty())
	{
		edge tp=aha.front();aha.pop();
		int v=tp.to;
		int len=G[v].size();
		for(int i=0;i<len;i++)
		{
			edge nx=G[v][i];
			if(d[nx.to]>d[v]+nx.w1)
			{
				d[nx.to]=d[v]+nx.w1;
				d2[nx.to]=d2[v]+nx.w2;
				aha.push((edge){nx.to,d[nx.to],d2[nx.to]});
			}
			else if(d[nx.to]==d[v]+nx.w1)
			{
				if(d2[nx.to]>d2[v]+nx.w2)
				{
					d[nx.to]=d[v]+nx.w1;
					d2[nx.to]=d2[v]+nx.w2;
					aha.push((edge){nx.to,d[nx.to],d2[nx.to]});
				}
			}
		}
	}
}

void add_edge(int u,int v,int w1,int w2)
{
	edge now={v,w1,w2};
	G[u].push_back(now);
}
