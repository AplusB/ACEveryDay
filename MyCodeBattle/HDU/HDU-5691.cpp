#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1e7 + 2;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef std::pair<int, int> pii;

LL w[20];
LL dp[1<<16][16];
int num[20], n;
const LL inf = (1ll<<60);

LL dfs(int s, int k) {
    int len = __builtin_popcount(s);
    if (dp[s][k] != -inf) return dp[s][k];

    if (num[len - 1] >= 0)
        if (k != num[len - 1]) return -inf;
    if (len == 1) return 0;

    for (int i = 0; i < n; ++i)
     if (i != k && ((s >> i) & 1))
        dp[s][k] = std::max(dp[s][k], dfs(s^(1<<k), i) + w[k]*w[i]);
    return dp[s][k];
}

int main() {
    //ROP;
    int T;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d:\n", ++cases);
        scanf("%d", &n);
        MS(num, -1);

        int s = (1<<n);
        for (int i = 0; i < n; ++i) {
            std::cin >> w[i];
            int tmp;
            scanf("%d", &tmp);
            if (tmp == -1) continue;
            num[tmp] = i;
        }
        if (n == 1) {
            puts("0");
            continue;
        }

        for (int i = 0; i < s; ++i)
            for (int j = 0; j < n; ++j) dp[i][j] = -inf;

        LL ans = -inf;
        for (int i = 0; i < n; ++i)
        ans = std::max(ans, dfs((1<<n) - 1, i));
        std::cout << ans << '\n';
    }
    return 0;
}
