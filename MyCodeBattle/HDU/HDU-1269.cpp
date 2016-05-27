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
const int MAXN = 100000+10;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//const int seed = 131;
int cases = 0;
typedef std::pair<int, int> pii;

bool vis[MAXN];
int lowlink[MAXN], dfn[MAXN];
int scc_cnt, time_stamp;
std::stack<int> stk;
std::vector<int> G[MAXN];

int dfs(int u) {
    lowlink[u] = dfn[u] = ++time_stamp;
    stk.push(u);
    vis[u] = true;
    for (int i = 0; i < SZ(G[u]); ++i) {
        int v = G[u][i];
        if (!dfn[v]) lowlink[u] = std::min(dfs(v), lowlink[u]);
        else if (vis[v]) lowlink[u] = std::min(lowlink[u], dfn[v]);
    }
    if (dfn[u] == lowlink[u]) {
        ++scc_cnt;
        while (true) {
            int u = stk.top(); stk.pop();
            if (dfn[u] == lowlink[u]) break;

        }
    }
    return lowlink[u];
}


int main() {
    ROP;
    int n, m;
    while (scanf("%d%d", &n, &m)) {
        if (!n && !m) break;
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            dfn[i] = 0;
            scc_cnt = 0;
            time_stamp = 0;
            G[i].clear();
        }
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) if (!vis[i])
            dfs(i);
        puts(scc_cnt == 1 ? "YES" : "NO");
    }
    return 0;
}

