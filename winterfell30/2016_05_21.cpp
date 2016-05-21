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
const int maxn = 7 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
int a[maxn], p[maxn];
LL dp[1<<17][17];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            p[i] = -1;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d%d", &a[i], &x);
            if (x != -1) p[x] = i;
        }
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -INF;
        if (p[0] != -1)
            dp[(1<<p[0])][p[0]] = 0;
        else
            for (int i = 0; i < n; i++) dp[1<<i][i] = 0;
        for (int s = 1; s < (1 << n); s++)
        {
            int num = __builtin_popcount(s);
            for (int i = 0; i < n; i++)
                if (dp[s][i] != -INF)
                {
                    for (int j = 0; j < n; j++)
                        if ((s & (1 << j)) == 0 && (p[num] == -1 || p[num] == j))
                        {
                        //printf("%d %d %d\n", s, j, dp[s][j]);
                            dp[s|(1<<j)][j] = max(dp[s|(1<<j)][j], dp[s][i] + a[j] * a[i]);
                        }
                }
        }
        LL ans = -INF;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[(1<<n)-1][i]);
        printf("Case #%d:\n", ncase);
        printf("%I64d\n", ans);
    }
    return 0;
}
