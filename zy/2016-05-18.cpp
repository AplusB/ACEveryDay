
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define MAX 100007
using namespace std;

vector<int> e[MAX],c[MAX];
set<int> st;
int fa[MAX][20];
int p[MAX];
int dfn[MAX];
int dis[MAX];
int cid;
int d[MAX];
bool vis[MAX];

void dfs ( int u , int f )
{
    dfn[++cid] = u;
    p[u] = cid;
    for ( int i = 1 ; i < 20 ; i++ )
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for ( int i = 0 ; i < e[u].size() ; i++ )
    {
        int v = e[u][i];
        if ( v == f )
            continue;
        d[v] = d[u] + 1;
        dis[v] = dis[u] + c[u][i];
        fa[v][0] = u;
        dfs ( v , u );
    }
}

int lca ( int u , int v )
{
    if ( d[u] < d[v] )
        swap ( u , v );
    for ( int i = 19 ; i >= 0 ; --i )
    {
        if ( d[fa[u][i]] >= d[v] )
            u = fa[u][i];
        if ( u == v )
            return u;
    }
    for ( int i = 19 ; i >= 0 ; i-- )
        if ( fa[u][i] != fa[v][i] )
        {
            v = fa[v][i];
            u = fa[u][i];
        }
    return fa[u][0];
}

int add ( int u )
{
    if ( st.empty() ) return 0;
    int x,y;
    set<int>::iterator it = st.lower_bound(p[u]) , itx = it;
    itx--;
    if ( it == st.end() || it == st.begin())
    {
        it = st.begin();
        itx = st.end();
        itx--;
    }
    y = (*it);
    x = (*itx);
    y = dfn[y];
    x = dfn[x];
    return dis[u] - dis[lca(x,u)] - dis[lca(y,u)] + dis[lca(x,y)];
}




int main()
{
    int t,ca,n,q;
    scanf("%d",&t);
    ca=1;
    while(t--)
    {
        st.clear();
        cid=0;
        scanf("%d%d",&n,&q);
        for(int i=0;i<=n;i++)
        {
            vis[i]=false;
            e[i].clear();
            c[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[x].push_back(y);
            e[y].push_back(x);
            c[x].push_back(z);
            c[y].push_back(z);
        }
        fa[1][0]=1;
        d[1]=1;
        dis[1]=0;
        dfs (1,-1);
        int sum = 0;
        printf("Case #%d:\n",ca++);
        while(q--)
        {
            int x,y;
            scanf ("%d%d",&x,&y);
            int temp;
            if(x==1)
            {
                if(!vis[y])
                {
                    vis[y]=true;
                    if(st.size()==0)
                    {
                        st.insert(p[y]);
                    }
                    else
                    {
                        temp=add(y);
                        st.insert(p[y]);
                        sum+=temp;
                    }
                }
            }
            else
            {
                if(vis[y])
                {
                    vis[y]=false;
                    st.erase(p[y]);
                    if (!st.empty())
                        sum-=add(y);
                }
            }
            printf ("%d\n",sum);
        }
    }
}
