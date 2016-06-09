#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[100][100];
int n;
char ss[100];

LL dfs(int l, int r)
{
    if(l > r) return dp[l][r] = 0;
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 1;
    dp[l][r] = 0;
    if(dp[l+1][r-1] == -1)
        dp[l+1][r-1] = dfs(l+1, r-1);
    if(dp[l+1][r] == -1)
        dp[l+1][r] = dfs(l+1, r);
    if(dp[l][r-1] == -1)
        dp[l][r-1] = dfs(l, r-1);
    if(ss[l] == ss[r]) dp[l][r] += dp[l+1][r-1]+1;
    return dp[l][r] += dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
}

void solve()
{
    scanf("%s",ss+1);
    n = (int)strlen(ss+1);
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            int k = i+j-1;
            if(ss[j] == ss[k])
                dp[j][k] += dp[j+1][k-1]+1;
            dp[j][k] += dp[j+1][k]+dp[j][k-1]-dp[j+1][k-1];
        }
    }
    //dfs(1, n);
    printf("%lld\n", dp[1][n]);
}


int main()
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
