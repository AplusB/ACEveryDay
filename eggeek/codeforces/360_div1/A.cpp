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
#define N 100010
int n, m, col[N];
vi e[N];

void dfs(int cur, int c) {
  col[cur] = c;
  for (int i: e[cur]) if (col[i] == -1) dfs(i, 1-c);
}

int main() {
  while (cin >> n >> m) {
    for (int i=1; i<=n; i++) e[i].clear();
    for (int i=0; i<m; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    memset(col, -1, sizeof(col));
    for (int i=1; i<=n; i++) if (col[i] == -1) dfs(i, 0);
    bool flag = true;
    for (int i=1; i<=n; i++) {
      for (int u: e[i]) if (col[i] == col[u]) {
        flag = false;
        break;
      }
      if (!flag) break;
    }
    if (flag) {
      vi c[2];
      for (int i=1; i<=n; i++) c[col[i]].push_back(i);
      for (int i=0; i<2; i++) {
        printf("%d\n", SZ(c[i]));
        for (int j=0; j<SZ(c[i]); j++) printf("%d%c", c[i][j], j+1<SZ(c[i])?' ': '\n');
      }
    } else printf("-1\n");
  }
  return 0;
}
