#include <bits/stdc++.h>
using namespace std;
int dp[15001];
int sum[2][15001];
int n, k, s;
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &k, &s);
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i <= s; ++i)
            sum[0][i] = 1;
        for(int i = 1; i <= n; ++i)
        {
            sum[i & 1][0] = 0;
            for(int j = 1; j <= s; ++j)
            {
                int l, r;
                l = max(0, j - k);
                r = j - 1;
                if(l - 1 < 0)
                    dp[j] = sum[(i-1)&1][r];
                else
                    dp[j] = (sum[(i-1)&1][r] - sum[(i-1)&1][l - 1] + 100000007) % 100000007;
                sum[i&1][j] = (sum[i&1][j - 1] + dp[j]) % 100000007;
            }
        }
        printf("Case %d: %d\n", _case++, dp[s]);
    }
    return 0;
}
