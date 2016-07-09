#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 100010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
using namespace std;
struct node
{
   int to,x;
};
vector<node>v[N];
int ans,vis[N],dis[N],n,m,ans1=3;
int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i].to,s=v[x][i].x;
        if(vis[xx]==x) continue;
        if(vis[xx]!=-1)
        {
            ans=gcd(ans,abs(dis[x]+s-dis[xx]));
            continue;
        }
        vis[xx]=x;
        dis[xx]=dis[x]+s;
        dfs(xx);
    }
}
int bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x]=0;
    dis[x]=0;
    int mx=0,mi=0;
    while(q.size())
    {
        int xx=q.front();q.pop();
        mx=max(mx,dis[xx]);
        mi=min(mi,dis[xx]);
        for(int i=0;i<v[xx].size();i++)
        {
            int xxx=v[xx][i].to,s=v[xx][i].x;
            if(vis[xxx]==xx) continue;
            if(vis[xxx]!=-1) continue;
            vis[xxx]=xx;
            dis[xxx]=dis[xx]+s;
            q.push(xxx);
        }
    }
    return mx-mi+1;
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        node e;
        e.to=y,e.x=1;
        v[x].push_back(e);
        e.to=x,e.x=-1;
        v[y].push_back(e);
    }
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=n;i++) if(vis[i]==-1) vis[i]=0,dis[i]=0,dfs(i);
    if(ans) for(ans1=3;ans1<ans&&ans%ans1;ans1++);
    else
    {
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=n;i++) if(vis[i]==-1) ans+=bfs(i);
    }
    if(ans<3) ans=ans1=-1;
    cout<<ans<<" "<<ans1<<endl;
    return 0;
}

