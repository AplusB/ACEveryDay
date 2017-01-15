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
#define K 5005
int g[N][N], n, m, k, s[K], d[K];
int dp[K][N];

void floyd() {
  for (int i=1; i<=n; i++) g[i][i] = 0;
  for (int x=1; x<=n; x++) {
    for (int i=1; i<=n; i++) if (i != x) {
      for (int j=1; j<=n; j++) if (j != i && j != x) {
        if (g[i][x] == -1) continue;
        if (g[x][j] == -1) continue;
        if (g[i][j] == -1) g[i][j] = g[i][x] + g[x][j];
        else g[i][j] = min(g[i][j], g[i][x] + g[x][j]);
        //printf("update: g[%d][%d] by g[%d][%d] (%d) + g[%d][%d] (%d) = %d\n",
        //    i, j, i, x, g[i][x], x, j, g[x][j], g[i][j]);
      }
    }
  }
}

struct node {
  int i, j;
};

queue<node> q;

void update(int i, int j, int dpval, int val) {
  if (val == -1) return;
  if (dp[i][j] == -1) {
    dp[i][j] = dpval + val;
    q.push(node{i, j});
  } else if (dp[i][j] > val + dpval) {
    dp[i][j] = val + dpval;
    q.push(node{i, j});
  }
}

int bfs() {
  memset(dp, -1, sizeof(dp));
  if (g[1][s[1]] == -1) return -1;
  q.push({1, s[1]});
  dp[1][s[1]] = g[1][s[1]];
  int ans = -1;
  while (!q.empty()) {
    node c = q.front(); q.pop();
    //printf("c: {%d, %d} dp: %d\n", c.i, c.j, dp[c.i][c.j]);
    int i = c.i, j = c.j;
    if (i == k) {
      if (g[j][d[i]] != -1)
        ans = ans == -1? dp[i][j] + g[j][d[i]]: min(ans, dp[i][j] + g[j][d[i]]);
      continue;
    }
    if (g[j][s[i+1]] != -1 && g[s[i+1]][d[i]] != -1)
      update(i+1, d[i], dp[i][j], g[j][s[i+1]] + g[s[i+1]][d[i]]);
    if (g[j][d[i]] != -1 && g[d[i]][s[i+1]] != -1)
      update(i+1, s[i+1], dp[i][j], g[j][d[i]] + g[d[i]][s[i+1]]);
  }
  return ans;
}

int solve() {
  cin >> n >> m >> k;
  memset(g, -1, sizeof(g));
  for (int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (g[a][b] == -1) g[a][b] = g[b][a] = c;
    else {
      g[a][b] = min(g[a][b], c);
      g[b][a] = min(g[b][a], c);
    }
  }
  for (int i=1; i<=k; i++) scanf("%d%d", &s[i], &d[i]);
  floyd();
  int ans = bfs();
  return ans;
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
