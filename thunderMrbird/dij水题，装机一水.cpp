#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int inf=10000005;
int a[1005][1005];
int dis[1005];
bool vis[1005];
int m,n;
void dij()
{
    for(int i=1;i<=n;i++)
        dis[i]=a[n][i];
        vis[n]=1;
    for(int i=2;i<=n;i++)
    {
        int t=0,p=inf;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<p)
            {
                t=j;
                p=dis[j];
            }
        }
        if(t==0) break;
        vis[t]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            dis[j]=min(dis[j],dis[t]+a[t][j]);
        }
    }
}
void init()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        a[i][j]=inf;
}
int main()
{
    int x,y,t;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        init();
        while(m--)
        {
            scanf("%d %d %d",&x,&y,&t);
            a[x][y]=a[y][x]=min(a[x][y],t);
        }
        dij();
        printf("%d\n",dis[1]);
    }
    return 0;
}
