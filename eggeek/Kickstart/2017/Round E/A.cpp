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
#define N 305
const ll mod = 1000000007ll;
char s[N];
int n, dp[N][N][N];
ll h[N][N];
set<ll> hs[N];

int dfs(int pos, int l, int r) {
  if (pos == 0) {
    return dp[pos][l][r] = 1;
  }
  if (dp[pos][l][r] != -1) return dp[pos][l][r];
  int res = dfs(pos-1, l, r) + 1;
  for (int j=pos-1; pos-j+1<=j; j--) {
    ll v = h[j][pos];
    for (int i=0; i<j; i++) if (hs[i].find(v) != hs[i].end()) {
      int tmp = dfs(j-1, j, pos) + 2;
      if (h[l][r] == v) tmp--;
      res = min(res, tmp);
    }
  }
  //printf("dp[%d][%d][%d]=%d\n", pos, l, r, res);
  return dp[pos][l][r] = res;
}

int solve_sml() {
  for (int i=0; i<n; i++) hs[i].clear();
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      hs[i].insert(h[j][i]);
    }
  }
  memset(dp, -1, sizeof(dp));
  return dfs(n-1, n, n);
}

void update(int& oldv, int newv) {
  if (oldv == -1) oldv = newv;
  else oldv = min(oldv, newv);
}

int solve_large() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i=0; i<n; i++) {
    int tmp = INF;
    for (int l=0; l<=i; l++)
      for (int r=l; r<=i; r++) if (dp[i][l][r] != -1)
        tmp = min(tmp, dp[i][l][r]);
    if (tmp != INF) {
      for (int l=0; l<=i; l++)
        for (int r=l; r<=i; r++)
          update(dp[i][l][r], tmp+1);
    }
    for (int l=0; l<=i; l++)
      for (int r=l; r<=i; r++) update(dp[i+1][l][r], dp[i][l][r]+1);
    for (int l=0; l<=i; l++)
      for (int r=l; r<=i; r++) {
        int len = r - l + 1;
        if (i+len < n && h[l][r] == h[i+1][i+len])
          update(dp[i+len][l][r], dp[i][l][r]+1);
      }
    if (i == n-1) return tmp;
  }
  assert(false);
  return 0;
}

int solve() {
  scanf("%s", s);
  n = strlen(s);
  for (int i=0; i<n; i++) {
    h[i][i] = s[i] - 'a' + 1;
    for (int j=i+1; j<n; j++) {
      h[i][j] = (h[i][j-1] * 28) + (s[j] - 'a' + 1);
      if (h[i][j] >= mod) h[i][j] %= mod;
    }
  }
  return solve_large();
}

int main() {
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    int ans = solve();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
