#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=25;
const int inf=2e9+9;

struct edge
{
    int to,cap,rev;
};

vector<edge> G[maxn];
int level[maxn];
int iter[maxn];

int n,m;
int gg[maxn][maxn];
int num[maxn];

void add_edge(int from,int to,int cap);
void bfs(int s);
int dfs(int v,int t,int f);
int max_flow(int s,int t);

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(gg,0,sizeof(gg));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            gg[u][v]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            num[i]=i;
        do
        {
            for(int i=0;i<maxn;i++)
                G[i].clear();
            num[n]=num[0];
            for(int i=1;i<=n;i++)
            {
                int lt=num[i-1],rt=num[i];
                for(int j=0;j<n;j++)
                {
                    if(gg[j][lt]==1 || gg[j][rt]==1) continue;
                    add_edge(i,j+n+1,1);
                }
                add_edge(0,i,1);
                add_edge(i+n,2*n+1,1);
            }
            ans=max(ans,max_flow(0,2*n+1));
        }while(next_permutation(num+1,num+n) && ans!=n);
        printf("%d\n",n-ans);
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
