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

struct Point {
    LL cnt, sum, sqrsum;
    Point(LL a, LL b, LL c) : cnt(a), sum(b), sqrsum(c) {}
    Point() {}
};

Point dp[20][7][7][2][2];
bool vis[20][7][7][2][2];
LL w[20];
int arr[20];

Point dfs(int pos, int sum, int mod, bool isContain, bool isLimit) {
    if (pos < 0) {
        if (!isContain && sum && mod) return Point(1, 0, 0);
        return Point(0, 0, 0);
    }
    if (vis[pos][sum][mod][isContain][isLimit]) return dp[pos][sum][mod][isContain][isLimit];
    vis[pos][sum][mod][isContain][isLimit] = true;
    Point ret = Point(0, 0, 0);
    int limit = isLimit ? arr[pos] : 9;
    for (int i = 0; i <= limit; ++i) {
        Point next = dfs(pos - 1, (sum + i) % 7, (mod*10 + i) % 7, isContain | (i == 7), isLimit && i == limit);
        LL preSum = i*w[pos]%MOD;
        ret.cnt = (ret.cnt + next.cnt) % MOD;
        ret.sum = (ret.sum + preSum*next.cnt + next.sum) % MOD;
        ret.sqrsum = (ret.sqrsum + preSum*preSum%MOD*next.cnt%MOD + next.sqrsum) % MOD;
        ret.sqrsum = (ret.sqrsum + 2*preSum*next.sum) % MOD;
    }
    return dp[pos][sum][mod][isContain][isLimit] = ret;
}

int resolve(LL n) {
    int pos = 0;
    while (n) {
        arr[pos++] = n % 10;
        n /= 10;
    }
    return pos;
}

LL solve(LL n) {
    MS(vis, 0);
    int len = resolve(n);
    return dfs(len - 1, 0, 0, false, true).sqrsum;
}

int main() {
    //ROP;
    w[0] = 1;
    for (int i = 1; i < 20; ++i) w[i] = (w[i - 1]*10) % MOD;

    int T;
    scanf("%d", &T);
    while (T--) {
        LL L, R;
        std::cin >> L >> R;
        std::cout << (solve(R) - solve(L - 1) + MOD) % MOD << '\n';
    }
    return 0;
}
