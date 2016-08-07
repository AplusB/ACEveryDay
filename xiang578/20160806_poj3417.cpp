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
typedef long long ll;
const int N=100000+10;
int n,m,cnt[N],fa[20][N],dep[N],lg;
int head[N],edge[5*N],next[5*N],tot;
ll ans;

void dfs(int v,int p,int d)
{
    fa[0][v]=p;
    dep[v]=d;
    for(int i=head[v]; i!=-1; i=next[i])
    {
        int u=edge[i];
        if(u!=p)
            dfs(u,v,d+1);
    }
}

void init()
{
    dfs(1,-1,0);
    lg=0;
    while((1<<(lg))<=n) lg++;
    for(int k=0; k+1<lg; k++)
    {
        for(int v=1; v<=n; v++)
        {
            if(fa[k][v]<0) fa[k+1][v]=-1;
            else fa[k+1][v]=fa[k][fa[k][v]];
        }
    }
}

int lca(int u,int v)
{
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0; k<lg; k++)
    {
        if((dep[v]-dep[u]) >> k & 1)
            v=fa[k][v];
    }
    if(u==v) return u;
    for(int k=lg-1; k>=0; k--)
    {
        if(fa[k][u]!=fa[k][v])
        {
            u=fa[k][u];
            v=fa[k][v];
        }
    }
    return fa[0][u];
}

void get(int v,int p)
{

    for(int i=head[v]; i!=-1; i=next[i])
    {
        int u=edge[i];
        if(u!=p)
        {
            get(u,v);
            cnt[v]+=cnt[u];
        }
    }

    if(p!=-1)
    {
        if(cnt[v]==0) ans+=m;
        else if(cnt[v]==1) ans+=1;
    }

}

int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            cnt[i]=0;
            head[i]=-1;
        }
        tot=0;
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            edge[tot]=u;
            next[tot]=head[v];
            head[v]=tot;
            tot++;

            edge[tot]=v;
            next[tot]=head[u];
            head[u]=tot;
            tot++;
        }
        init();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            int k=lca(u,v);
            if(k==u||k==v)
            {
                cnt[k]-=1;
                if(k==u) cnt[v]+=1;
                else cnt[u]+=1;
            }
            else
            {
                cnt[k]-=2;
                cnt[u]++;
                cnt[v]++;
            }
        }
        ans=0;
        get(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}

/*
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
typedef long long ll;
const int N=100000+10;
int n,m,cnt[N],fa[N],dep[N];
vector<int>g[N];
ll ans;

void dfs(int v,int p,int d)
{
    fa[v]=p;
    dep[v]=d;
    for(int i=0;i<g[v].size();i++)
    {
        if(g[v][i]!=p)
            dfs(g[v][i],v,d+1);
    }
}

void lca(int u,int v)
{
    while(dep[u]>dep[v])
    {
        cnt[u]++;
        u=fa[u];
    }
    while(dep[v]>dep[u])
    {
        cnt[v]++;
        v=fa[v];
    }
    while(u!=v)
    {
        cnt[u]++;
        cnt[v]++;
        u=fa[u];
        v=fa[v];
    }
}
void get(int x,int p)
{
    if(p!=-1)
    {
        if(cnt[x]==0) ans+=m;
        else if(cnt[x]==1) ans+=1;
    }

    for(int i=0;i<g[x].size();i++)
    {
        if(p!=g[x][i])
            get(g[x][i],x);
    }
}
int main()
{
    int u,v;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            cnt[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,-1,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            lca(u,v);
        }
        ans=0;
        get(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}
*/
