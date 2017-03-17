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
#define N 5003
int dp[N][N], n, m, cnt[N][N], s[N];
double x[N];

void statistic() {
  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) cnt[j][i] = cnt[j-1][i] + (s[j] == i);
  }
}

int count(int l, int r, int id) {
  if (l > r) return 0;
  int res = cnt[r][id] - cnt[l-1][id];
  assert(res >= 0);
  return res;
}

void update(int& var, int newv) {
  if (var == -1 || var > newv) var = newv;
}

int solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][1] = 0;
  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n+1; j++) if (dp[i][j] != -1) {
      //printf("cur: dp[%d][%d]: %d, update dp[%d][%d] by %d\n", i, j, dp[i][j], i, j+1, dp[i][j] + (s[j] > i));
      if (j <= n)
        update(dp[i][j+1], dp[i][j] + (s[j] > i));
      //printf("cur: dp[%d][%d]: %d, update dp[%d][%d] by %d\n", i, j, dp[i][j], i+1, j, dp[i][j] + count(j, n, i));
      update(dp[i+1][j], dp[i][j] + count(j, n, i));
    }
  }
  return dp[m][n+1];
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    cin >> s[i] >> x[i];
  }
  statistic();
  cout << solve() << endl;
  return 0;
}
