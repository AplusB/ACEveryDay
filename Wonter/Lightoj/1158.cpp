#include <bits/stdc++.h>
using namespace std;

char str[20];
int dp[1 << 10][1010];
int d, len;
int f[15];
int fac[15];
int cnt[15];
int dfs(int s, int mod, int deep)
{
    if(s == 0)
    {
        if(mod == 0)
            return dp[s][mod] = 1;
        return dp[s][mod] = 0;
    }
    if(dp[s][mod] != -1)
        return dp[s][mod];
    dp[s][mod] = 0;
    for(int i = 0; i < len; ++i)
        if(s & (1 << i))
            dp[s][mod] += dfs(s - (1 << i),  (mod - (str[i] - '0') * f[deep] % d + d) % d, deep + 1);
    return dp[s][mod];
}
int main()
{
    fac[0] = 1;
    for(int i = 1; i <= 10; ++i)
        fac[i] = fac[i - 1] * i;
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(dp, -1, sizeof(dp));
        scanf("%s", str);
        len = strlen(str);
        scanf("%d", &d);
        f[0] = 1 % d;
        for(int i = 1; i < 10; ++i)
            f[i] = f[i - 1] * 10 % d;
        int ans = dfs((1 << len) - 1, 0, 0);
        for(int i = 0; str[i]; ++i)
            ++cnt[str[i] - '0'];
        for(int i = 0; i < 10; ++i)
            ans /= fac[cnt[i]];
        printf("Case %d: %d\n", _case++, ans);
    }
    return 0;
}
