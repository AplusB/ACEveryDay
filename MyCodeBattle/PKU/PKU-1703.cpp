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

int fa[MAXN], rank[MAXN];

int find(int n) {
    if (n == fa[n]) return n;
    int tmp = fa[n];
    fa[n] = find(fa[n]);
    rank[n] = (rank[tmp] + rank[n]) % 2;
    return fa[n];
}

void merge(int u, int v) {
    int x = find(u), y = find(v);
    fa[x] = y;
    rank[x] = (1 + rank[u] + rank[v]) % 2;
}

int main() {
    //ROP;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            rank[i] = 0;
        }
        while (m--) {
            char cmd[2];
            int u, v;
            scanf("%s%d%d", cmd, &u, &v);
            if (cmd[0] == 'A') {
                if (find(u) != find(v)) puts("Not sure yet.");
                else puts(rank[u] == rank[v] ? "In the same gang." : "In different gangs.");
            }
            else {
                merge(u, v);
            }
        }
    }
    return 0;
}
