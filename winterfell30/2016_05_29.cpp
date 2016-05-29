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
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int Mod = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
int dp[1010];
vector<pair<int, int> > G[maxn];
int n, m;

void dfs(int u, int fa, int limit)
{
    int flag = 1;
    dp[u] = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first;
        int cost = G[u][i].second;
        if (v == fa)  continue;
        flag = 0;
        //printf("66 %d %d %d\n", u, v, cost);
        dfs(v, u, limit);
        if (cost <= limit) dp[u] += min(dp[v], cost);
        else dp[u] += dp[v];
        //printf("%d %d\n", u, dp[u]);
    }
    if (flag) dp[u] = 1000001;
}

int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    while (scanf("%d%d", &n, &m) && n)
    {
        for (int i = 1; i <= n; i++)
            G[i].clear();
        int mmax = -1;
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(MP(v, w));
            G[v].push_back(MP(u, w));
            mmax = max(mmax, w);
        }
        int l = 1, r = mmax;
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            dfs(1, -1, mid);
            //printf("%d %d %d %d %d %d\n", mid, dp[1], dp[2], dp[3], dp[4], dp[5]);
            if (dp[1] <= m)
            {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
