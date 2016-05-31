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
const int MAXN = 1e5 + 10;
const int MOD = 1e5;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef std::pair<int, int> pii;

std::priority_queue<int> Q;
int in[MAXN], arr[MAXN];
std::vector<int> G[MAXN];
int n;

void solve() {
    for (int i = 1; i <= n; ++i) if (!in[i])
        Q.push(i);

    int pos = n + 1;
    while (!Q.empty()) {
        int u = Q.top(); Q.pop();
        arr[--pos] = u;
        for (int i = 0; i < SZ(G[u]); ++i) if (--in[G[u][i]] == 0)
            Q.push(G[u][i]);
    }
    std::reverse(arr+1, arr+1+n);
    int minv = arr[1];
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        minv = std::min(minv, arr[i]);
        ans += minv;

    }
    std::cout << ans << '\n';
}

int main() {
   // ROP;
    int T;
    scanf("%d", &T);
    while (T--) {
        int m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
            in[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            ++in[v];
        }
        solve();
    }
    return 0;
}
