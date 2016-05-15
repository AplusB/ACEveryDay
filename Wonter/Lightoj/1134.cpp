#include <bits/stdc++.h>
using namespace std;

long long dp[100050];
int arr[100050];
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        long long ans = 0;
        int start = 0;
        for(int i = 1; i <= n; ++i)
        {
            start = (start + m - arr[i] % m) % m;
            ++dp[(start + arr[i] % m) % m];
            ans += dp[start];
        }
        printf("Case %d: %lld\n", _case++, ans);
    }
    return 0;
}
