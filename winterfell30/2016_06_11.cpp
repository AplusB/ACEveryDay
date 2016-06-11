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
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
LL p[20], r[20];
LL dp[20];
vector<int> G[20];

void dfs(int u, int fa, int status)
{
    LL Min, Max;
    if ((1 << u) & status) dp[u] = r[u], Min = r[u], Max = r[u];
    else dp[u] = p[u], Min = p[u], Max = p[u];
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == fa) continue;
        dfs(v, u, status);
        if ((1 << v) & status) Min = min(Min, r[v]);
        else Min = min(Min, p[v]);
        if ((1 << v) & status) Max = max(Max, r[v]);
        else Max = max(Max, p[v]);
        dp[u] += dp[v];
    }
    dp[u] -= ceil((Max - Min) / 1000.0) * 666 * (u + 1);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &r[i], &p[i]);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LL ans = -1e18;
    for (int s = 0; s < (1 << n); s++)
    {
        dfs(0, -1, s);
        ans = max(ans, dp[0]);
    }
    printf("%lld\n", ans);
    return 0;
}
