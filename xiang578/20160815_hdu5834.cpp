#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
    int to,w;
};
vector<node>g[N];
int n,dp[3][N],V[N],id[N],ans[N];

//dp[0]回来最大值，dp[1]不回来最大值，dp[2]不回来次大值
void dfs(int u,int fa)
{
    int v,w,mi,w1,w2,f=0,s=0;
    dp[0][u]=V[u];
    id[u]=-1;
    for(int i=0; i<g[u].size(); i++)
    {
        v=g[u][i].to;
        w=g[u][i].w;
        if(v==fa) continue;
        dfs(v,u);
        w1=max(0,dp[0][v]-2*w);
        w2=max(0,dp[1][v]-w)-max(0,dp[0][v]-2*w);
        dp[0][u]+=w1;
        if(w2>f)
        {
            s=f;
            f=w2;
            id[u]=v;
        }
        else if(w2>s)
        {
            s=w2;
        }
    }
    dp[1][u]=dp[0][u]+f;
    dp[2][u]=dp[0][u]+s;
}
//sum1从父节点不回来，sum2从父节点回来
void get(int u,int fa,int sum1,int sum2)
{
    //printf("%d %d %d %d %d\n",u,sum1,sum2,dp[0][u],dp[1][u]);
    ans[u]=max(sum1+dp[0][u],sum2+dp[1][u]);
    int tmp1=0,tmp2=0,v,w;
    for(int i=0; i<g[u].size(); i++)
    {
        v=g[u][i].to;
        w=g[u][i].w;
        if(v==fa) continue;
        tmp2=max(sum2+dp[0][u]-max(dp[0][v]-2*w,0)-2*w,0);
        tmp1=0;
        tmp1=max(tmp1,sum1+dp[0][u]-max(dp[0][v]-2*w,0)-w);
        if(v!=id[u])
        {
            tmp1=max(tmp1,sum2+dp[1][u]-max(dp[0][v]-2*w,0)-w);
        }
        else
        {
            tmp1=max(tmp1,sum2+dp[2][u]-max(dp[0][v]-2*w,0)-w);
        }
        get(v,u,tmp1,tmp2);
    }
}
int main()
{
    int _,u,v,w,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&V[i]);
        }
        for(int i=1; i<=n; i++)
        {
            g[i].clear();
        }
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node t;
            t.w=w;
            t.to=v;
            g[u].push_back(t);
            t.to=u;
            g[v].push_back(t);
        }
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        dfs(1,0);
        get(1,0,0,0);
        printf("Case #%d:\n",++cas);
        for(int i=1; i<=n; i++)
        {
            printf("%d\n",ans[i]);
        }
        /*for(int i=1; i<=n; i++)
        {
            printf("%d %d %d\n",dp[0][i],dp[1][i],dp[2][i]);
        }*/
    }
    return 0;
}
