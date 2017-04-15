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
#define N 55
int n, p, r[N], q[N][N];
bool vis[N][N];

bool cmp(int u, int v) { return u < v; }

int check(double t, double need, double cur) {
  if (cur < 0.9 * t * need) return 1;
  else if (cur > 1.1 * t * need) return -1;
  else return 0;
}

int bslb(int need, int cur) {
  int lft = 1, rht = INF, best = INF;
  while (lft <= rht) {
    int t = (lft + rht) >> 1;
    int f = check(t, need, cur);
    //printf("check(%d, %d, %d)= %d\n", t, need, cur, f);
    if (f == 0) {
      best = t;
      rht = t - 1;
    } else if (f == 1) {
      rht = t - 1;
    } else if (f == -1) {
      lft = t + 1;
    } else assert(false);
  }
  return best;
}

int bsub(int need, int cur ) {
  int lft = 1, rht = INF, best = -1;
  while (lft <= rht) {
    int t = (lft + rht) >> 1;
    int f = check(t, need, cur);
    if (f == 0) {
      best = t;
      lft = t + 1;
    } else if (f == 1) {
      rht = t - 1;
    } else if (f == -1) {
      lft = t + 1;
    } else assert(false);
  }
  return best;
}

pii calc(int need, int cur) {
  int lb = bslb(need, cur);
  int ub = bsub(need, cur);
  return {lb, ub};
}

int dfs(int row, int lb, int ub) {
  if (row == n) {
    return 1;
  }
  //printf("row:%d lb:%d ub:%d\n", row, lb, ub);
  for (int i=0; i<p; i++) if (!vis[row][i]) {
    pii rg = calc(r[row], q[row][i]);
    //printf("rg: {%d, %d}\n", rg.first, rg.second);
    if (rg.first > ub) return 0;
    if (rg.second < lb) continue;
    vis[row][i] = 1;
    int f = dfs(row+1, max(rg.first, lb), min(rg.second, ub));
    if (f == 1) return 1;
  }
  return 0;
}

int solve() {
  cin >> n >> p;
  for (int i=0; i<n; i++) cin >> r[i];
  for (int i=0; i<n; i++) {
    for (int j=0; j<p; j++) cin >> q[i][j];
    sort(q[i], q[i]+p, cmp);
  }
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  for (int i=0; i<p; i++) {
    pii rg = calc(r[0], q[0][i]);
    if (rg.first <= rg.second) {
      cnt += dfs(0, 0, INF);
    }
  }
  return cnt;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = solve();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
