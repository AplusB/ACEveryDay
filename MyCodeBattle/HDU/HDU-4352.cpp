#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
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
const int MAXN = 1e5+10;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

int k;
LL dp[20][1<<10][11];
int arr[20];

LL dfs(int pos, int state, bool isLimit, bool isZero) {
    if (pos < 0) return __builtin_popcount(state) == k;
    if (!isLimit && ~dp[pos][state][k]) return dp[pos][state][k];
    LL res = 0;

    int limit = isLimit ? arr[pos] : 9;
    for (int i = 0; i <= limit; ++i) {
        if (i == 0 && isZero)
            res += dfs(pos - 1, 0, isLimit && i == limit, true);
        else {
            int newState = state;
            for (int j = i; j < 10; ++j) if ((state >> j) & 1) {
                newState ^= (1 << j);
                break;
            }
            newState |= (1 << i);
            res += dfs(pos - 1, newState, isLimit && i == limit, false);
        }
    }
    if (!isLimit) dp[pos][state][k] = res;
    return res;
}

LL solve(LL n) {
    int len = 0;
    while (n) {
        arr[len++] = n % 10;
        n /= 10;
    }

    return dfs(len - 1, 0, true, true);
}

int main() {
    //ROP;
    int T;
    scanf("%d", &T);
    MS(dp, -1);
    while (T--) {
        printf("Case #%d: ", ++cases);
        LL l, r;
        std::cin >> l >> r >> k;
        std::cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}


