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
//using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define lowbit(x) ((x) & (-x))
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
typedef pair<int, int> pii;

int w;
int arr[20];
int dp[10][200000];

int resolve(int n) {
    int pos = 0;

    while (n) {
        arr[pos++] = n % 10;
        n /= 10;
    }
    return pos;
}

int get_weigh(int n) {
    int weigh = 1, res = 0;
    while (n) {
        res += n % 10 * weigh;
        weigh <<= 1;
        n /= 10;
    }
    return res;
}

int dfs(int pos, int num, bool isLimit) {
    if (pos < 0) return num >= 0;
    if (num < 0) return 0;
    int res = dp[pos][num];
    if (!isLimit && res != -1) return res;
    res = 0;

    int limit = isLimit ? arr[pos] : 9;
    for (int i = 0; i <= limit; ++i) {
        int newNum = num - (1<<pos) * i;
        res += dfs(pos - 1, newNum, isLimit && i==limit);
    }
    return isLimit ? res : dp[pos][num] = res;
}

void solve(int n) {
    int len = resolve(n);
    printf("Case #%d: %d\n", ++cases, dfs(len - 1, w, true));
}

int main() {
    int T;
    scanf("%d", &T);
    MS(dp, -1);
    while (T--) {
        int A, n;
        scanf("%d%d", &A, &n);
        w = get_weigh(A);
        solve(n);
    }
    return 0;
}
