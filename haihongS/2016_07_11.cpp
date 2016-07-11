#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=600+9;
const int inf=2e9+9;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[maxn];
int level[maxn];
int iter[maxn];

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
	int n,f,d;
    while(~scanf("%d%d%d",&n,&f,&d))
    {
        for(int i=0;i<maxn;i++)
            G[i].clear();

        for(int i=1;i<=n;i++)
        {
            int s1,s2;
            scanf("%d%d",&s1,&s2);
            while(s1--)
            {
                int u;
                scanf("%d",&u);
                add_edge(u,i+200,1);
            }
            while(s2--)
            {
                int u;
                scanf("%d",&u);
                add_edge(i+300,u+100,1);
            }
            add_edge(i+200,i+300,1);
        }
        for(int i=1;i<=f;i++)
            add_edge(0,i,1);
        for(int i=1;i<=d;i++)
            add_edge(100+i,500,1);
        int ans=max_flow(0,500);
        printf("%d\n",ans);
    }
	return 0;
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
