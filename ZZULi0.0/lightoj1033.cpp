#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 105;

int dp[N][N];
char ss[N];

int dfs(int l, int r)
{
    if(r <= l) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    if(ss[l] == ss[r]) return dp[l][r] = dfs(l+1,r-1);
    else
        return dp[l][r] = min(dfs(l+1,r),dfs(l,r-1))+1;
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    scanf("%s",ss+1);
    int n = (int)strlen(ss+1);

    int ans = dfs(1,n);
    printf("%d\n",ans);
}

int main(void)
{
    int t,cnt = 0;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
