#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;
int pre[500],c[500],dp[1000000],a[500],vis[500],flag;
int t;
void dfs(int x)
{
    //cout<<x<<endl;
    if(vis[x]) flag=1;
    if(flag) return;
    int y=pre[x];
    if(y==-1) return;
    a[y]+=a[x];
    t-=a[x];
    if(t<0) flag=1;
    pre[x]=-1;
    c[y]--;
    vis[x]=1;
    dfs(y);
}
int main()
{
    int n,q,x,y;
    scanf("%d%d%d",&n,&q,&t);
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        pre[x]=y;
        c[y]++;
    }
    flag=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(c[i]) continue;
        if(pre[i]==-1) continue;
        dfs(i);
    }
    for(int i=1;i<=n;i++) if(c[i]>0||pre[i]!=-1) flag=1;
  //  cout<<t<<" "<<flag<<endl;
    if(flag)
    {
        cout<<0<<endl;
        return 0;
    }
  //  for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=t;j++)
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }
    cout<<dp[t]<<endl;
    return 0;
}
