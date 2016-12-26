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
#define N 101
ll dp[N][N][N];
set<pll> q[N][N];
int n, m, k, p[N][N], c[N];

void update(ll& x, ll& y) {
  if (y == -1) return;
  if (x == -1) x = y;
  else x = min(x, y);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i=1; i<=n; i++) scanf("%d", &c[i]);
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) scanf("%d", &p[i][j]);
  }
  memset(dp, -1, sizeof(dp));
  if (c[1] == 0) {
    for (int i=1; i<=m; i++) {
      dp[1][1][i] = p[1][i];
      q[1][1].insert({p[1][i], i});
    }
  } else {
    dp[1][1][c[1]] = 0;
    q[1][1].insert({0, c[1]});
  }
  for (int i=2; i<=n; i++) {
    for (int t=1; t<=k; t++) {
      if (c[i] == 0) {
        for (int j=1; j<=m; j++) {
          update(dp[i][t][j], dp[i-1][t][j]);
          for (pll x: q[i-1][t-1]) if (x.second != j) {
            update(dp[i][t][j], x.first);
            break;
          }
          if (dp[i][t][j] != -1) dp[i][t][j] += p[i][j];
          if (dp[i][t][j] != -1) q[i][t].insert({dp[i][t][j], j});
        }
      } else {
        // same color as previous
        update(dp[i][t][c[i]], dp[i-1][t][c[i]]);
        // different color
        for (pll x: q[i-1][t-1]) if (x.second != c[i]) {
          update(dp[i][t][c[i]], x.first);
          break;
        }
        if (dp[i][t][c[i]] != -1) q[i][t].insert({dp[i][t][c[i]], c[i]});
      }
    }
  }
  ll ans = -1;
  for (int i=1; i<=m; i++) update(ans, dp[n][k][i]);
  cout << ans << endl;
  return 0;
}
