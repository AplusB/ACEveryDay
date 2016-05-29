#include <bits/stdc++.h>
#define N 105
using namespace std;

int dp[N][N],w,n,k;
struct nodes
{
    int x,y;
    bool operator < (const nodes &b)const
    {
        if(y == b.y)
            return x < b.x;
        return y <b.y;
    }
    void sets()
    {
        scanf("%d %d",&x,&y);
    }
} Point[N];
int nxt[N],cnt[N];

int dfs(int cur,int ed)
{
    if(cur > n || ed >= k) return 0;

    if(dp[cur][ed] != -1) return dp[cur][ed];

    return dp[cur][ed] = max(dfs(cur+1,ed),dfs(nxt[cur],ed+1)+cnt[cur]);
}


void solve()
{
    scanf("%d %d %d",&n,&w,&k);

    for(int i = 1; i <= n; i++)
        Point[i].sets();
    memset(dp,-1,sizeof(dp));
    sort(Point+1,Point+n+1);
    int i,j;
    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n && Point[j].y -  Point[i].y <= w; j++);
        nxt[i] = j;
        cnt[i] = j - i;
    }

    printf("%d\n",dfs(1,0));
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}


