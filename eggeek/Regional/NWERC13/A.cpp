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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 2002
struct Edge {
  int u, v, c;
};
vector<Edge> e, ans;
vector<pii> g[N];
int n, a[N][N], d[N][N], p[N];
bool use[N][N];

int find_pa(int u) {
  if (p[u] == u) return u;
  return p[u] = find_pa(p[u]);
}

bool cmp(Edge x, Edge y) { return x.c < y.c; }

void mst() {
  rep(i, 1, n+1) rep(j, 1, n+1) use[i][j] = false;
  rep(i, 1, n+1) p[i] = i;
  rep(i, 1, n+1) g[i].clear();
  sort(e.begin(), e.end(), cmp);
  for (Edge i: e) {
    int u = find_pa(i.u);
    int v=  find_pa(i.v);
    if (u != v) {
      p[u] = v;
      ans.push_back(i);
      g[i.u].push_back(make_pair(i.v, i.c));
      g[i.v].push_back(make_pair(i.u, i.c));
      use[i.v][i.u] = use[i.u][i.v] = true;
    }
  }
  assert(ans.size() == n-1);
}

void dfs(int pos, int rt, int pre) {
  for (pii i: g[pos]) if (i.first != pre) {
    d[rt][i.first] = d[rt][pos] + i.second;
    dfs(i.first, rt, pos);
  }
}

void solve() {
  e.clear();
  ans.clear();
  rep(i, 1, n+1) rep(j, 1, n+1) scanf("%d", &a[i][j]);
  rep(i, 1, n+1) rep(j, i+1, n+1) e.push_back(Edge{i, j, a[i][j]});
  mst();
  rep(i, 1, n+1) rep(j, 1, n+1) d[i][j] = i==j?0: INF;
  rep(i, 1, n+1) dfs(i, i, 0);
  int minC = INF, u = 1, v = 2;
  rep(i, 1, n+1) rep(j, 1, n+1) if (a[i][j] < d[i][j] && a[i][j] < minC) {
    minC = a[i][j];
    u = i; v = j;
  }
  g[u].push_back(make_pair(v, a[u][v]));
  g[v].push_back(make_pair(u, a[u][v]));
  ans.push_back(Edge{u, v, a[u][v]});
  for (Edge i: ans) printf("%d %d %d\n", i.u, i.v, i.c);
}

bool check() {

  rep(i, 1, n+1) rep(j, 1, n+1) d[i][j] = i==j?0: INF;
  for (Edge i: ans) d[i.u][i.v] = d[i.v][i.u] = i.c;
  rep(k, 1, n+1)
    rep(i, 1, n+1) if (i != k)
    rep(j, 1, n+1) if (j != k && j != i) {
      if (d[i][k] == INF || d[k][j] == INF) continue;
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

  rep(i, 1, n+1) {
    rep(j, 1, n+1) printf("%d ", d[i][j]); printf("\n");
  }
  rep(i, 1, n+1) rep(j, 1, n+1) if (a[i][j] != d[i][j]) return false;
  return true;
}

int main() {
  bool flag = false;
  while (scanf("%d", &n) != EOF) {
    if (flag) printf("\n");
    else flag = true;
    solve();
    //assert(check());
  }
  return 0;
}
