#include <stack>
#include <stdio.h>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <string>
#include <map>
#include <cmath>
//using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(p, num) memset(p, num, sizeof(p))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define FOR(i, a, b) for (int i=(a); (i) < (b); (i)++)
#define FOOR(i, a, b) for (int i = (a); (i)<=(b); (i)++)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 20;
const int MOD = 1e9 + 7;
const int dir[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

bool mp[MAXN][MAXN];
LL dp[1<<MAXN][MAXN];

int getLowest(int n) {
    for (int i = 0; i < 20; ++i) if (n & (1 << i))
        return i;
}

int main() {
    //ROP;
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        mp[u][v] = mp[v][u] = true;
    }
    for (int i = 0; i < n; ++i) dp[1<<i][i] = 1;

    LL ans = 0;
    for (int s = 0; s < (1 << n); ++s) {
        int lowestPoint = getLowest(s);
        for (int end = 0; end < n; ++end) if ((s & (1 << end)) && dp[s][end]) {
            for (int to = lowestPoint; to < n; ++to) if (mp[end][to]) {
                if (s & (1 << to)) {
                    if ((1 << to | 1 << end) == s) continue;
                    if (to == lowestPoint) ans += dp[s][end];
                }
                else {
                    dp[s | (1 << to)][to] += dp[s][end];
                }
            }
        }
    }
    printf("%I64d\n", ans/2);
    return 0;
}

