#include <bits/stdc++.h>

using namespace std;
const int maxn=400+9;
const int inf=2e9+9;

int n,m;
int mapp[maxn][maxn],d[maxn][2],last[maxn][2];
int dd[maxn][maxn][2];

struct edge
{
    int to,cost;
};
typedef pair<int,int> P;
vector<edge> G[maxn][2];

void add_edge(int u,int v,int cost,int ff);
int Dijkstra(int s,int ff);

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        //init
        memset(mapp,0,sizeof(mapp));
        for(int i=0;i<maxn;i++)
            G[i][0].clear(),G[i][1].clear();
        for(int i=0;i<maxn;i++)
        {
            for(int j=0;j<maxn;j++)
            {
                if(i==j) dd[i][j][0]=dd[i][j][1]=0;
                else dd[i][j][0]=dd[i][j][1]=inf;
            }
        }


        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            mapp[u][v]=mapp[v][u]=1;
            add_edge(u,v,1,0);
            add_edge(v,u,1,0);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(mapp[i][j]==0)
                    add_edge(i,j,1,1),add_edge(j,i,1,1);
            }
        }
        Dijkstra(1,0);
        Dijkstra(1,1);
        if(d[n][0]==inf || d[n][1]==inf)
            printf("-1\n");
        else
            printf("%d\n",max(d[n][0],d[n][1]));


    }
    return 0;
}

int Dijkstra(int s,int ff)
{
    for(int i=0;i<maxn;i++) d[i][ff]=inf,last[i][ff]=-1;
    d[s][ff]=0;
    priority_queue<P,vector<P>,greater<P> >aha;
    while(!aha.empty()) aha.pop();
    aha.push(P(0,s));
    while(!aha.empty())
    {
        P tp=aha.top();aha.pop();
        int v=tp.second;
        if(d[v][ff]<tp.first) continue;
        for(int i=0;i<G[v][ff].size();i++)
        {
            edge now=G[v][ff][i];
            if(d[now.to][ff]>d[v][ff]+now.cost)
            {
                d[now.to][ff]=d[v][ff]+now.cost;
                last[now.to][ff]=v;
                aha.push(P(d[now.to][ff],now.to));
            }
        }
    }
    return 0;
}


void add_edge(int u,int v,int cost,int ff)
{
    edge now;
    now.to=v,now.cost=cost;
    G[u][ff].push_back(now);
}

