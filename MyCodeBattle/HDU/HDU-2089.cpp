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
const int MAXN = 10 + 10;
const int MOD = 1e9 + 7;
const int dir[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

int dp[MAXN][2][2];
int buf[100];
int dfs(int pos, bool isSixSelected, bool isLimited) {
    if (pos == -1) return 1;
    if (~dp[pos][isSixSelected][isLimited]) return dp[pos][isSixSelected][isLimited];
    int cur = isLimited ? buf[pos] : 9;

    int ret = 0;
    for (int i = 0; i <= cur; ++i) {
        if ((isSixSelected && i==2) || i == 4) continue;
        ret += dfs(pos - 1, i==6, isLimited && i==cur);
    }

    return dp[pos][isSixSelected][isLimited] = ret;
}

int solve(int n) {
    MS(dp, -1);
    int pos = 0;
    while (n) {
        buf[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, false, true);
}

int main() {
   // ROP;
    int n, m;

    while (scanf("%d%d", &n, &m)) {

        if (n + m == 0) break;
        printf("%d\n", solve(m) - solve(n - 1));
    }
    return 0;
}

