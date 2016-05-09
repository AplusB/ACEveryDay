#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
LL dp[1<<20][20];
bool a[20][20];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        a[u][v] = a[v][u] = 1;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[1<<i][i] = 1;
    LL ans = 0;
    for (int s = 1; s < (1 << n); s++)
    {
        int st = 0;
        for (int i = 0; i < n; i++)
            if (s & (1 << i))
                st = i, i = n;
        for (int e = st; e < n; e++)
            if (s & (1 << e))
                for (int i = st; i < n; i++)
                    if (!(s & (1 << i)) && a[e][i])
                    {
                        dp[s|(1<<i)][i] += dp[s][e];
                        if (a[i][st] && __builtin_popcount(s|(1<<i)) >= 3)
                            ans += dp[s][e];
                    }
    }
    cout << ans / 2 << endl;
    return 0;
}
