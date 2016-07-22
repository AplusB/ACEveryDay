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
#define N 500
int v, e, val[N];
bool m[N][N];
vector<pii> g;

void solve() {
  g.clear();
  memset(m, 0, sizeof(m));
  rep(i, 0, v) scanf("%d", &val[i]);
  rep(i, 0, e) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    g.push_back(make_pair(x, y));
    m[x][y] = true;
    m[y][x] = true;
  }
  int ans = 0;
  rep(i, 0, v) ans = max(ans, val[i]);
  rep(i, 0, e) ans = max(ans, val[g[i].first] + val[g[i].second]);
  rep(i, 0, e) {
    int x = g[i].first;
    int y = g[i].second;
    rep(j, 0, v) if (j != x && j != y && m[x][j] && m[y][j]) {
      ans = max(ans, val[x] + val[y] + val[j]);
    }
  }
  rep(i, 0, e) {
    int u1 = g[i].first;
    int v1 = g[i].second;
    rep(j, i+1, e) {
      int u2 = g[j].first;
      int v2 = g[j].second;
      if (u2 != u1 && u2 != v1 && v2 != u1 && v2 != v1) {
        if (m[u1][u2] && m[u1][v2] && m[v1][u2] && m[v1][v2]) {
          ans = max(ans, val[u1] + val[u2] + val[v1] + val[v2]);
        }
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d", &v, &e) != EOF) solve();
  return 0;
}
