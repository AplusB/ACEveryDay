#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int Mod = 1000000007;
const int maxn = 300 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
int n, m;
bool c[maxn][maxn];
int a[maxn];
int dp[maxn][maxn];

void solve()
{
    for (int len = 1; len <= n; len++)
        for (int l = 1; l <= n; l++)
        {
            int r = l + len;
            if (r > n) break;
            dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            for (int i = l; i <= r; i++)
                dp[l][r] = max(dp[l][r], dp[l][i] + dp[i+1][r]);
            if (c[l][r] && dp[l+1][r-1] == r - l - 1)
                dp[l][r] = max(dp[l][r], dp[l+1][r-1] + 2);
            for (int i = l + 1; i <= r; i++)
            {
                if (c[l][i] && dp[l+1][i-1] == i - l - 1)
                    dp[l][r] = max(dp[l][r], dp[l+1][i-1] + 2 + dp[i+1][r]);
                if (c[i][r] && dp[i+1][r-1] == r - i - 1)
                    dp[l][r] = max(dp[l][r], dp[l][i-1] + dp[i+1][r-1] + 2);
                if (c[l][i] && c[i][r] && dp[l+1][i-1] == i - l - 1 && dp[i+1][r-1] == r - i - 1 && a[r] - a[i] == a[i] - a[l])
                    dp[l][r] = max(dp[l][r], dp[l+1][i-1] + dp[i+1][r-1] + 3);
            }
        }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= m; i++)
        {
            int x;
            scanf("%d", &x);
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    if (a[j] - a[i] == x)
                        c[i][j] = 1;
        }
        solve();
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
