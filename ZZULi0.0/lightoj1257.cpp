#include <bits/stdc++.h>
#define N 30000*2
using namespace std;

int head[N],tot,dp[N];
int s,mw;
struct nodes
{
    int to,next,w;
}Edge[N];

void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));

}
void add(int f,int t,int w)
{
    Edge[tot].to = t;
    Edge[tot].w = w;
    Edge[tot].next = head[f];
    head[f] = tot++;
}
void dfs(int cur,int pre,int curw)
{
    if(curw > mw)
    {
        s = cur;
        mw = curw;
    }
    for(int i = head[cur]; i != -1; i = Edge[i].next)
    {
        int to = Edge[i].to;
        if(to != pre)
        {
            dfs(to,cur,curw+Edge[i].w);
            dp[to] = max(dp[to],curw+Edge[i].w);
        }
    }
}

void solve()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i = 0; i < n-1; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    s = 0;
    mw = 0;
    dfs(1,-1,0);
    dfs(s,-1,0);
    dfs(s,-1,0);

    for(int i = 0 ; i < n; i++)
    {
        printf("%d\n",dp[i]);
    }
}


int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cnt);
        solve();
    }
}
