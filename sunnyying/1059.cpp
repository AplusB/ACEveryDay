#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#define INF 0x3f3f3f3f
#define LL long long
#define N 300
using namespace std;
int a[N][N];
int px[N];
int py[N];
int nx,ny;
int dx[N];
int dy[N];
int dis;
bool vis[N];
bool searchpath()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=nx;i++)
       if(px[i]==-1)
       {
          Q.push(i);
          dx[i]=0;
       }
    while(!Q.empty())
    {
       int u=Q.front();
       Q.pop();
       if(dx[u]>dis) break;
       for(int v=1;v<=ny;v++)
       {
          if(a[u][v]&&dy[v]==-1)
          {
             dy[v]=dx[u]+1;
             if(py[v]==-1) dis=dy[v];
             else
             {
                dx[py[v]]=dy[v]+1;
                Q.push(py[v]);
             }
          }
       }
    }
    return dis!=INF;
}
int findpath(int u)
{
    for(int v=1;v<=ny;v++)
    {
       if(!vis[v]&&a[u][v]&&dy[v]==dx[u]+1)
       {
          vis[v]=1;
          if(py[v]!=-1&&dy[v]==dis) continue;
          if(py[v]==-1||findpath(py[v]))
          {
             py[v]=u;px[u]=v;
             return 1;
          }
       }
    }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(px,-1,sizeof(px));
    memset(py,-1,sizeof(py));
    while(searchpath())
    {
       memset(vis,0,sizeof(vis));
       for(int i=1;i<=nx;i++)
          if(px[i]==-1) res+=findpath(i);
    }
    return res;
}
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        nx=ny=n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
             scanf("%d",&x);
             if(x) a[i][j]=1;
        }
        int ans=MaxMatch();
        if(ans==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
