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
const int MAXN = 20;
const int MOD = 2520;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef std::pair<int, int> pii;

LL dp[20][50][2530];
std::map<int, int> mp;
int cnt, arr[20];

int get_lcm(int a, int b) {
    return a / std::__gcd(a, b) * b;
}

LL dfs(int pos, int lcm, int rem, bool isLimit) {
    if (pos == -1) return rem % lcm == 0;
    if (~dp[pos][mp[lcm]][rem] && !isLimit) return dp[pos][mp[lcm]][rem];
    LL res = 0;
    res = 0;
    int limit = isLimit ? arr[pos] : 9;
    for (int i = 0; i <= limit; ++i) {
        if (i) res += dfs(pos - 1, get_lcm(i, lcm), (rem*10 + i)%MOD, isLimit && i == limit);
        else res += dfs(pos - 1, lcm, rem*10%MOD, isLimit && i == limit);
    }
    if (!isLimit) dp[pos][mp[lcm]][rem] = res;
    return res;
}

LL solve(LL n) {
    int len = 0;
    while (n) {
        arr[len++] = n % 10;
        n /= 10;
    }

    return dfs(len - 1, 1, 0, true);
}

int main() {
    //ROP;
    int T;
    scanf("%d", &T);
    MS(dp, -1);
    for (int i = 1; i <= MOD; ++i) if (MOD % i == 0) {
        mp[i] = ++cnt;
    }

    while (T--) {
        LL l, r;
        std::cin >> l >> r;
        std::cout << solve(r) - solve(l - 1) << '\n';
    }
    return 0;
}
