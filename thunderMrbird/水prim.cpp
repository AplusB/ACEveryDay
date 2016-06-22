#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
typedef long long ll;
int n,m;
const int inf=1e9+1;
int mp[55][55];
int dis[55];
bool vis[55];
int prim()
{
        int ans=0;
        memset(vis,0,sizeof(vis));
      for(int i=0;i<=n;i++)
        dis[i]=mp[1][i];
        vis[1]=1;
      for(int i=1;i<n;i++)
      {
              int minn=inf;
              int t=1;
              for(int j=1;j<=n;j++)
              {
                      if(!vis[j]&&minn>dis[j])
                      {
                              minn=dis[j];
                              t=j;
                      }
              }
              vis[t]=1;
              ans+=minn;
              for(int j=1;j<=n;j++)
              {
                      if(!vis[j])
                      dis[j]=min(dis[j],mp[t][j]);
              }
      }
      return ans;
}
void init()
{
        for(int i=0;i<=n;i++)
        {
                for(int j=0;j<=n;j++)
                {
                        mp[i][j]=i==j?0:inf;
                }
        }
        return;
}
int main()
{
        int x,y,t;
        while(scanf("%d",&n)&&n)
        {
                scanf("%d",&m);
                init();
                for(int i=0;i<m;i++)
                {
                        scanf("%d %d %d",&x,&y,&t);
                        mp[y][x]=mp[x][y]=min(t,mp[x][y]);
                }
                printf("%d\n",prim());
        }
        return 0;
}
