#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1000000;
int n,m;
int x,y,t;
int mp[205][205];
int dist[205];
int vis[205];
void dijkstra()
{
    for(int i=1;i<=n;i++)
        dist[i]=mp[1][i];
    for(int j=1;j<=n;j++)
    {
        int minn=inf,sav=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&dist[i]<minn)
            {
                minn=dist[i];
                sav=i;
            }
        }
        vis[sav]=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                dist[i]=min(dist[i],dist[sav]+mp[sav][i]);
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF&&(m||n))
    {
        memset(mp,inf,sizeof(mp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&t);
            mp[x][y]=mp[y][x]=t;
        }
        dijkstra();
        printf("%d\n",dist[n]);
    }
    return 0;
}
