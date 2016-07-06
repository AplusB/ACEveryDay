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
#define N 101000
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
typedef long long LL;
using namespace std;
stack<int>s;
vector<int>v[N],g[N];
int sum=1,id=1,num[N],belong[N],low[N],dfn[N],vis[N],n;
void Tarjan(int x)
{
    low[x]=dfn[x]=id++;vis[x]=1;s.push(x);
    for(int i=0;i<v[x].size();i++)
    {
        int xx=v[x][i];
        if(!dfn[xx])
        {
            Tarjan(xx);
            low[x]=min(low[x],low[xx]);
        }
        else if(vis[xx]) low[x]=min(low[x],dfn[xx]);
    }
    if(low[x]==dfn[x])
    {
        while(s.size())
        {
            int xx=s.top();s.pop();
            num[sum]++;
            belong[xx]=sum;
            vis[xx]=0;
            if(xx==x) break;
        }
        sum++;
    }
}
void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    id=sum=1;
    while(s.size()) s.pop();
    for(int i=0;i<=n;i++) v[i].clear();
}
int r[N],dp[N],fa[N];
long long cnt[N],flag=0,mod;
queue<int>q;
int main()
{
    int x,y,m;
    scanf("%d%d%lld",&n,&m,&mod);
    init();
    while(m--)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
    memset(r,0,sizeof(r));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            int xx=v[i][j];
            if(belong[i]==belong[xx]) continue;
            g[belong[i]].push_back(belong[xx]);
            r[belong[xx]]++;
        }
    }
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(fa,0,sizeof(fa));
    int ans=0;
    for(int i=1;i<sum;i++) if(r[i]==0) q.push(i),vis[i]=1;
    while(q.size())
    {
        x=q.front();q.pop();
        if(dp[x]==0) dp[x]=num[x],cnt[x]=1;
        if(ans<dp[x]) ans=dp[x],flag=cnt[x];
        else if(ans==dp[x]) flag=(flag+cnt[x])%mod;
        for(int i=0;i<g[x].size();i++)
        {
            int xx=g[x][i];
            r[xx]--;
            if(r[xx]==0&&vis[xx]==0) q.push(xx),vis[xx]=1;
            if(fa[xx]==x) continue;
            fa[xx]=x;
            if(dp[xx]<dp[x]+num[xx])
            {
                dp[xx]=dp[x]+num[xx];
                cnt[xx]=cnt[x];
            }
            else if(dp[xx]==dp[x]+num[xx]) cnt[xx]=(cnt[xx]+cnt[x])%mod;
        }
    }
    cout<<ans<<endl<<flag<<endl;
    return 0;
}
