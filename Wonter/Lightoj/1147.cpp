#include <bits/stdc++.h>
using namespace std;

long long dp[100050];
int arr[120];
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        int sum = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        dp[0] = 1;
        int t = n / 2;
        for(int i = 1; i <= n; ++i)
            for(int j = sum; j >= arr[i]; --j)
                dp[j] |= dp[j - arr[i]] << 1;
        int a = -100000000, b = 100000000;
        for(int i = 0; i <= sum; ++i)
        {
            if(dp[i] & (1ll << t))
            {
                if(2 * i - sum < b - a)
                {
                    a = min(i, sum - i);
                    b = sum - a;
                }
            }
        }
        printf("Case %d: %d %d\n", _case++, a, b);
    }
    return 0;
}
