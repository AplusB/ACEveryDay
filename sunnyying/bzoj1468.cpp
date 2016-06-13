#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 100100
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
struct node
{
    int to,s;
};
int n,k,size[N],f[N],num,root,sum,a[N],dis[N],vis[N];
ll ans=0;
vector<node>v[N];
void findroot(int x,int fa)
{
    f[x]=0;size[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i].to;
        if(xx==fa||vis[xx]) continue;
        findroot(xx,x);
        size[x]+=size[xx];
        f[x]=max(f[x],size[xx]);
    }
    f[x]=max(f[x],num-size[x]);
    if(f[x]<f[root]) root=x;
}
void finddis(int x,int fa)
{
    a[sum++]=dis[x];
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i].to;
        if(xx==fa||vis[xx]) continue;
        dis[xx]=dis[x]+v[x][i].s;
        finddis(xx,x);
    }
}
int cal(int x,int s)
{
    int ans=0;
    dis[x]=s;sum=0;
    finddis(x,0);
    sort(a,a+sum);
    int l=0,r=sum-1;
    while(l<r)
    {
        if(a[l]+a[r]<=k) ans=ans+r-l,l++;
        else r--;
    }
    return ans;
}
void solve(int x)
{
    ans=ans+cal(x,0);vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i].to;
        if(vis[xx]) continue;
        ans=ans-cal(xx,v[x][i].s);
        num=size[xx];root=0;
        findroot(xx,0);
        solve(root);
    }
}
int main()
{
   // freopen("in.in","r",stdin);
 //   freopen("out.out","w",stdout);
    int x,y,z;
    while(~scanf("%d%d",&n,&k)&&n+k)
    {
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            node e;
            e.to=y,e.s=z;
            v[x].push_back(e);
            e.to=x,e.s=z;
            v[y].push_back(e);
        }
        memset(size,0,sizeof(size));
        memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));
        num=n;root=0;f[0]=n+1;ans=0;
        findroot(1,0);
        solve(root);
        cout<<ans<<endl;
    }
    return 0;
}
