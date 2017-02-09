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
#define N 2001
struct Edge {
  int u, v, w;
};
vector<Edge> es;
vector<Edge> g[N];
int n, a[N][N], f[N], maxD;

bool cmp(Edge x, Edge y) { return x.w < y.w; }

int find_fa(int cur) {
  if (f[cur] == cur) return cur;
  else return f[cur] = find_fa(f[cur]);
}

bool dfs(int cur, int d, int pre, int root) {
  if (d > maxD) return false;
  if (d != a[root][cur]) return false;
  for (Edge i: g[cur]) if (i.v != pre) {
    bool res = dfs(i.v, d + i.w, cur, root);
    if (!res) return false;
  }
  return true;
}

bool verify() {
  int cnt = 0;
  for (int i=0; i<n; i++) if (f[i] == i) cnt++;
  return cnt == 1;
}

bool solve() {
  sort(ALL(es), cmp);
  for (int i=0; i<n; i++) f[i] = i;
  for (Edge i: es) {
    int u = i.u;
    int v = i.v;
    int fu = find_fa(u);
    int fv = find_fa(v);
    if (fu != fv) {
      f[fu] = fv;
      g[u].push_back(Edge{u, v, i.w});
      g[v].push_back(Edge{v, u, i.w});
    }
  }
  if (!verify()) return false;
  for (int i=0; i<n; i++) {
    if (!dfs(i, 0, -1, i)) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  maxD = -1;
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    scanf("%d", &a[i][j]);
    if (i != j && a[i][j]) es.push_back(Edge{i, j, a[i][j]});
    maxD = max(maxD, a[i][j]);
  }
  printf(solve()?"YES\n": "NO\n");
  return 0;
}
