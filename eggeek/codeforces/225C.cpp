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
#define N 1002
int n, m, x, y;
int dp[N][N][2], w[N][2];
char g[N][N];

void init() {
  memset(w, 0, sizeof(w));
  for (int i=0; i<m; i++) {
    w[i][0] = w[i][1] = n;
    for (int j=0; j<n; j++) {
      if (g[j][i] == '.') w[i][0]--;
      if (g[j][i] == '#') w[i][1]--;
    }
  }
}

void update(int& oldv, int newv) {
  if (oldv == -1) oldv = newv;
  else oldv = min(oldv, newv);
}

int solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 0;
  //for (int i=0; i<m; i++) printf("w[%d][0]: %d, w[%d][1]: %d\n", i, w[i][0], i, w[i][1]);
  for (int i=0; i<m; i++) {
    for (int j=0; j<=y; j++) {
      for (int k=0; k<2; k++) if (dp[i][j][k] != -1) {
        if (j >= x) {
          update(dp[i+1][1][1-k], dp[i][j][k] + w[i][1-k]);
        }
        if (j < y) {
          update(dp[i+1][j+1][k], dp[i][j][k] + w[i][k]);
        }
      }
    }
  }
  int ans = -1;
  for (int i=x; i<=y; i++)
    for (int j=0; j<2; j++) if (dp[m][i][j] != -1) update(ans, dp[m][i][j]);
  return ans;
}

int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i=0; i<n; i++) scanf("%s", g[i]);
  init();
  printf("%d\n", solve());
  return 0;
}
