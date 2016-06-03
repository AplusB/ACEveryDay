#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
const int N=2048;
const int inf=1<<24;

struct Edge
{
    int from,to,cap,flow;
};

vector<Edge>edges;
vector<int>G[N];
int s,t;
int vis[N];
int d[N];
int cur[N];

void AddEdge(int from,int to,int cap)
{
    Edge tp;
    tp.from=from,tp.to=to,tp.cap=cap,tp.flow=0;
    edges.push_back(tp);

    tp.from=to,tp.to=from,tp.cap=0,tp.flow=0;
    edges.push_back(tp);

    int g_size=edges.size();
    G[from].push_back(g_size-2);
    G[to].push_back(g_size-1);
}

bool BFS()
{
    memset(vis,0,sizeof(vis));
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=0; i<G[x].size(); i++)
        {
            Edge &e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

int DFS(int x,int a)
{
    if(x==t||a==0) return a;
    int flow=0,f;
    for(int &i=cur[x]; i<G[x].size(); i++)
    {
        Edge &e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
        {
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}

int Maxflow(int st,int ed)
{
    int flow=0;
    while(BFS())
    {
        memset(cur,0,sizeof(cur));
        flow+=DFS(st,inf);
    }
    return flow;
}

/*int main()
{
    int n,m,u,v,c;
    while(~scanf("%d%d",&n,&m))
    {
         edges.clear();
        for(int i=0; i<N; i++) G[i].clear();
        s=1;t=n;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        printf("%d\n",Maxflow(s,t));
    }
    return 0;
}*/

map<string,int>mp;

int main()
{
    edges.clear();
    for(int i=0; i<N; i++) G[i].clear();
    int a1,b1;
    mp.clear();
    string a,b;
    int n,w,tot=1;
    cin>>a>>b>>n;
    mp[a]=tot;
    s=tot++;
    mp[b]=tot;
    t=tot++;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>w;
        if(mp[a]==0)
        {
            mp[a]=tot;
            tot++;
        }
        if(mp[b]==0)
        {
            mp[b]=tot;
            tot++;
        }
        a1=mp[a];
        b1=mp[b];
        AddEdge(a1,b1,w);
    }
    printf("%d\n",Maxflow(s,t));
}
