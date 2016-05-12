#include <bits/stdc++.h>
using namespace std;

int arr[60];
int dp[2][500002];
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        int sum = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= sum; ++j)
            {
                dp[i & 1][j] = dp[(i - 1) & 1][j];
                if(j + arr[i] <= sum && dp[(i - 1) & 1][j + arr[i]] != -1)
                    dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j + arr[i]]);
                if(arr[i] - j >= 0 && dp[(i - 1) & 1][arr[i] - j] != -1)
                    dp[i & 1][j] = max(dp[i & 1][j], j + dp[(i - 1) & 1][arr[i] - j]);
                if(j - arr[i] >= 0 && dp[(i - 1) & 1][j - arr[i]] != -1)
                    dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - arr[i]] + arr[i]);
            }
        }
        if(dp[n & 1][0] == -1 || dp[n & 1][0] == 0)
            printf("Case %d: impossible\n", _case++);
        else
            printf("Case %d: %d\n", _case++, dp[n & 1][0]);
    }
    return 0;
}
