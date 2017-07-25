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
const ll mod = 100000000;
int n1, n2, n, k[2];
ll dp[N << 1][N][2][11];

void update(ll &s1, ll s2) {
  if (s1 == -1) s1 = s2;
  else s1 = (s1 + s2) % mod;
}

ll DP() {
  memset(dp, -1, sizeof(dp));
  dp[1][1][0][1] = 1;
  dp[1][0][1][1] = 1;
  for (int i=1; i<n; i++) {
    for (int j=0; j<=n1; j++) {
      for (int x=0; x<=k[0]; x++) if (dp[i][j][0][x] != -1) {
        if (j+1<=n1 && x+1<=k[0]) update(dp[i+1][j+1][0][x+1], dp[i][j][0][x]);
        if (i+1-j<=n2) update(dp[i+1][j][1][1], dp[i][j][0][x]);
      }
      for (int x=0; x<=k[1]; x++) if (dp[i][j][1][x] != -1) {
        if (j+1<=n1) update(dp[i+1][j+1][0][1], dp[i][j][1][x]);
        if (i+1-j<=n2 && x+1<=k[1]) update(dp[i+1][j][1][x+1], dp[i][j][1][x]);
      }
    }
  }
  ll res = 0ll;
  for (int i=0; i<2; i++)
    for (int j=1; j<=k[i]; j++) if (dp[n][n1][i][j] != -1) {
      res += dp[n][n1][i][j];
      res %= mod;
    }
  return res;
}

int main() {
  cin >> n1 >> n2 >> k[0] >> k[1];
  n = n1 + n2;
  ll ans = DP();
  cout << ans << endl;
  return 0;
}
