#include <bits/stdc++.h>
using namespace std;
 
int n, h;
int f[50], d[50], t[50], cnt[50][500];
int dp[50][500], nxt[50][500];
int ans[50];
int dfs(int pos, int time)
{
    if(time <= 0 || pos == n + 1)
        return dp[pos][time] = 0;
    if(dp[pos][time] != -1)
        return dp[pos][time];
    dp[pos][time] = 0;
    for(int i = time;i >= 0;i--)
    {
        int res = cnt[pos][i] + dfs(pos + 1, time - i - t[pos]);
        if(res > dp[pos][time])
        {
            dp[pos][time] = res;
            nxt[pos][time] = i;
        }
    }
    return dp[pos][time];
}
int main()
{
    /*
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    */
    int T;
    int _Case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(ans, 0, sizeof(ans));
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &n, &h);
        h *= 12;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &f[i]);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &d[i]);
        for(int i = 1; i <= n - 1; ++i)
            scanf("%d", &t[i]);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= h; ++j)
            {
                int tmp = max(f[i] - (j - 1) * d[i], 0);
                cnt[i][j] = cnt[i][j - 1] + tmp;
            }
        }
        dfs(1, h);
        printf("Case %d:\n", _Case++);
        int pos, time;
        pos = 1;
        time = h;
        while(time > 0)
        {
            ans[pos] = nxt[pos][time] * 5;
            time = time - nxt[pos][time] - t[pos];
            pos = pos + 1;
        }
        for(int i = 1;i <= n;++i)
        {
            if(i == 1)
                printf("%d", ans[1]);
            else
                printf(", %d", ans[i]);
        }
        printf("\n");
        printf("Number of fish expected: %d\n", dp[1][h]);
    }
    return 0;
}
