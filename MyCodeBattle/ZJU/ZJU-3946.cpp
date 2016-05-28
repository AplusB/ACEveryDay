#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int maxn = 3000 + 7;
const double eps = 1e-8;
const int MOD = 1000000009;
const double PI = acos(-1.0);

const int MAXN = 1e5 + 10;

struct Edge {
    int v, t, c;
};

set<int> used_edges;
vector<int> G[MAXN];
vector<Edge> edges;
LL dis[MAXN], cost[MAXN];
int fa[MAXN];
bool inq[MAXN];
int n;
queue<int> Q;

void sum() {
    LL ans_time = 0, ans_cost = 0;
    for (int i = 1; i < n; ++i) {
        ans_time += dis[i];
        ans_cost += cost[i];
    }

    printf("%lld %lld\n", ans_time, ans_cost);
}

void solve() {
    Q.push(0);
    dis[0] = cost[0] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if (dis[e.v] > dis[u] + e.t) {
                dis[e.v] = dis[u] + e.t;
                cost[e.v] = e.c;
                fa[e.v] = G[u][i];
                if (!inq[e.v]) {
                    inq[e.v] = true;
                    Q.push(e.v);
                }
            }
            else if (dis[e.v] == dis[u] + e.t) {
                if (cost[e.v] > e.c) {
                    cost[e.v] = e.c;
                    if (!inq[e.v]) {
                        inq[e.v] = true;
                        Q.push(e.v);
                    }
                }
            }
        }
    }

    sum();
}
void init() {
    for (int i = 0; i < n; ++i) {
        G[i].clear();
        inq[i] = false;
        dis[i] = (1ll<<60);
        cost[i] = (1ll << 60);
    }
    while (!Q.empty()) Q.pop();
    used_edges.clear();
    edges.clear();
}

void addEdge(int u, int v, int t, int c) {
    edges.push_back((Edge) {v, t, c});
    G[u].push_back(edges.size() - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {

        int m;
        scanf("%d%d", &n, &m);
        init();
        while (m--) {
            int u, v, t, c;
            scanf("%d%d%d%d", &u, &v, &t, &c);
            addEdge(u, v, t, c); addEdge(v, u, t, c);
        }

        solve();
    }
    return 0;
}
