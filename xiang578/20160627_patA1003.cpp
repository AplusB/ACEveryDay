//解题思路：最短路变形题，最后从终点dfs就可以找出长度相同的方案数了
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3fffffff;

struct node
{
    int to,w;
};

int c1,c2,n,m,ans;
int a[1024],d1[1024],vis[1024],d2[1024],inq[1024];
vector<node>g[1024];
void dfs(int x)
{
    if(x==c1)
    {
        ans++;
        return ;
    }
    for(int i=0;i<g[x].size();i++)
    {
        int u=g[x][i].to;
        int w=g[x][i].w;
        if(d1[u]+w==d1[x])
        {
            dfs(u);
        }
    }
}
void spfa()
{
    for(int i=0;i<n;i++)
    {
        d1[i]=inf;
        d2[i]=0;
        inq[i]=0;
    }
    queue<int>q;
    q.push(c1);
    d1[c1]=0;
    d2[c1]=a[c1];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].to;
            int w=g[u][i].w;
            if(d1[v]>d1[u]+w)
            {
                d1[v]=d1[u]+w;
                d2[v]=d2[u]+a[v];
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
            else if(d1[v]==d1[u]+w&&d2[v]<d2[u]+a[v])
            {
                d2[v]=d2[u]+a[v];
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    ans=0;
    dfs(c2);
    printf("%d %d\n",ans,d2[c2]);
}


int main()
{
    int u,v,w;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        node t;
        t.to=v;
        t.w=w;
        g[u].push_back(t);
        t.to=u;
        g[v].push_back(t);
    }
    spfa();
    return 0;
}
