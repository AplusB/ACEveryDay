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
#define INF (1e9 + 1)
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 2020
ll n, ts, tf, s[N], f[N], d[N];
ll dp[N][N];

void update(ll& oldv, ll newv) {
  if (oldv == -1 || oldv > newv) oldv = newv;
}

void do_case() {
  cin >> n >> ts >> tf;
  for (int i=1; i<n; i++) {
    cin >> s[i] >> f[i] >> d[i];
  }
  memset(dp, -1, sizeof(dp));
  dp[1][0] = 0;
  dp[1][1] = ts;
  for (int i=1; i<n; i++) {
    for (int j=0; j<=i; j++) if (dp[i][j] != -1 && dp[i][j] <= tf) {
      ll cur;
      if (dp[i][j] <= s[i]) cur = s[i] + d[i];
      else {
        ll x = (dp[i][j] - s[i] + f[i]-1) / f[i];
        cur = s[i] + x * f[i] + d[i];
      }
      //printf("cur state: dp[%d][%d](%lld), update dp[%d][%d] by %lld\n", i, j, dp[i][j], i+1, j, cur);
      update(dp[i+1][j], cur);
      //printf("cur state: dp[%d][%d](%lld), update dp[%d][%d] by %lld\n", i, j, dp[i][j], i+1, j+1, cur + ts);
      if (i+1 < n) update(dp[i+1][j+1], cur + ts);
    }
  }
  int ans = -1;
  for (int i=0; i<=n-1; i++) if (dp[n][i] != -1 && dp[n][i] <= tf) {
    ans = max(ans, i);
  }
  if (ans == -1) printf("IMPOSSIBLE\n");
  else printf("%d\n", ans);
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    do_case();
  }
  return 0;
}
