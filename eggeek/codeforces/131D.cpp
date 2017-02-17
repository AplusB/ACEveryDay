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
#define N 3001
int n, vis[N], root, cyc[N], dis[N];
vi g[N], path;

void dfs(int cur, int pre) {
  vis[cur] = true;
  path.push_back(cur);
  for (int i: g[cur]) if (i != pre) {
    if (root != -1) return;
    if (vis[i]) {
      root = i;
      while (!path.empty()) {
        int v = path.back();
        path.pop_back();
        assert(vis[v]);
        vis[v] = false;
        cyc[v] = true;
        if (v == i) break;
      }
      return;
    }
    else dfs(i, cur);
  }
  if (vis[cur]) {
    path.pop_back();
    vis[cur] = false;
  }

}

void dfs2(int cur, int pre, int d) {
  dis[cur] = d;
  vis[cur] = true;
  for (int i: g[cur]) if (i != pre && !vis[i]) {
    if (cyc[i]) dfs2(i, cur, 0);
    else dfs2(i, cur, d+1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  root = -1;
  dfs(1, -1);
  memset(vis, 0, sizeof(vis));
  dfs2(root, -1, 0);
  for (int i=1; i<=n; i++) printf("%d%c", dis[i], i<n?' ': '\n');
  return 0;
}
