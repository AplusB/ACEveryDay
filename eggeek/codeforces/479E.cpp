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
#define N 5002
const ll mod = 1000000007ll;
int n, a, b, k, l, r;
ll dp[N][N];

ll solve() {
  memset(dp, 0, sizeof(dp));
  for (int i=1; i<=r; i++) dp[0][i] = 1ll;
  for (int i=1; i<=k; i++) {
    for (int j=1; j<=r; j++) {
      dp[i][j+1] = (dp[i][j] + dp[i-1][j] - dp[i-1][j+1] + mod) % mod;
      for (int x=2*j; x<=2*j+1 && x<=r; x++) {
        dp[i][j+1] += dp[i-1][x];
        if (dp[i][j+1] >= mod) dp[i][j+1] %= mod;
      }
      if (dp[i][j+1] >= mod) dp[i][j+1] %= mod;
    }
  }
  return dp[k][l];
}

int main() {
  cin >> n >> a >> b >> k;
  if (a < b) r = b - 1;
  else r = n - b;
  l = abs(a-b);
  cout << solve() << endl;
  return 0;
}
