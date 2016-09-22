//“玲珑杯”ACM 热身赛 # 2.5
//B -- B-E
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[2048][2048], g[2048][2048], n;

int main()
{
    while(cin>>n)
    {
        n = 1 << n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%lld", &g[i][j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = 1000000000000000;

        for (int i = 0; i < n; ++i) dp[0][i] = 0;

        for (int i = 1; i < n; ++i) {
            int lobit = (i & -i);
            for (int prev = 0; prev < n; ++prev) {
                int start = (prev ^ lobit) & ~(lobit - 1);
                int end = start + lobit;
                for (int curr = start; curr < end; ++curr) {
                    dp[i][curr] = min(dp[i][curr], dp[i - 1][prev] + g[prev][curr]);
                }
            }
        }

        LL ret = 1000000000000000;
        for (int i = 0; i < n; ++i) ret = min(ret, dp[n - 1][i]);
        printf("%lld\n", ret);
    }
    return 0;
}
