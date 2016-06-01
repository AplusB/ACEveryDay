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

LL ans[MAXN];
int arr[MAXN];

void dfs(int l, int r) {
    if (l > r) return;
    int maxVal = -INF, minVal = INF;

    int minPos;
    for (int i = l; i <= r; ++i) {
        maxVal = std::max(arr[i], maxVal);
        if (arr[i] < minVal) {
            minVal = arr[i];
            minPos = i;
        }
    }
    ans[r - l + 1] = std::max(ans[r - l + 1], (LL)maxVal*minVal);
    dfs(l, minPos - 1);
    dfs(minPos + 1, r);
}

int main() {
    //ROP;
    int n;
    while (~scanf("%d", &n)) {
        MS(ans, 0);
        for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
        dfs(1, n);
        for (int i = n - 1; i >= 1; --i) ans[i] = std::max(ans[i], ans[i + 1]);
        for (int i = 1; i <= n; ++i) printf("%I64d\n", ans[i]);
    }
    return 0;
}
