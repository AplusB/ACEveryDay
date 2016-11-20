#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
#define INF 1e9
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 100010
struct edge {
  int to, w;
};
int n, m, pre[N];
vector<edge> g[N];
ll d[N];

struct cmp {
  bool operator() (const pii &x, const pii &y) {
    return x.second >= y.second;
  }
};
priority_queue<pii, vector<pii>, cmp> q;

void path(int cur) {
  if (pre[cur] != -1) path(pre[cur]);
  printf("%d ", cur);
}

void dijkstra(int s, int t) {
  memset(d, -1, sizeof(d));
  memset(pre, -1, sizeof(pre));
  d[s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    pii c = q.top(); q.pop();
    int v = c.first;
    for (edge e: g[v]) {
      int u = e.to;
      ll w = e.w;
      if (d[u] == -1 || c.second + w < d[u]) {
        d[u] = c.second + w;
        q.push({u, d[u]});
        pre[u] = v;
      }
    }
  }
  if (d[n] == -1) printf("-1\n");
  else {
    path(pre[n]);
    printf("%d\n", n);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back((edge){v, w});
    g[v].push_back((edge){u, w});
  }
  dijkstra(1, n);
  return 0;
}
