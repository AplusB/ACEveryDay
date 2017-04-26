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
#define N 1010
int n, a[26], l[N][N], vis[N][N];
ll dp[N][N];
string s;
const ll M = (ll)(1e9 + 7);

void solve() {
  for (int i=0; i<n; i++) {
    l[i][i] = a[s[i] - 'a'];
    for (int j=i+1; j<n; j++) {
      l[i][j] = min(l[i][j-1], a[s[j] - 'a']);
    }
  }
  dp[0][0] = 1;
  vis[0][0] = 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) if (vis[i][j]) {
      //printf("dp[%d][%d]: %lld\n", i, j, dp[i][j]);
      if (l[i-j][i] >= j+1) {
        //printf("l[%d][%d]: %d\n", i-j, i, l[i-j][i]);
        vis[i+1][j+1] = 1;
        dp[i+1][j+1] += dp[i][j];
        dp[i+1][j+1] %= M;
        //printf("update dp[%d][%d] = %lld\n", i+1, j+1, dp[i+1][j+1]);
        vis[i+1][0] = 1;
        dp[i+1][0] += dp[i][j];
        dp[i+1][0] %= M;
        //printf("update dp[%d][%d] = %lld\n", i+1, 0, dp[i+1][0]);
      }

    }
  }
  int maxl = 0;
  cout << dp[n][0] << endl;
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=n; j++) if (vis[i][j]) maxl = max(maxl, j);
  }
  cout << maxl << endl;
  ll cnt = 0;
  ll curl = 0;
  while (curl < n) {
    for (int nxt=n; nxt>=curl; nxt--) if (vis[nxt][nxt - curl]) {
      curl = nxt;
      cnt++;
      break;
    }
  }
  cout << cnt << endl;
}

int main() {
  cin >> n >> s;
  for (int i=0; i<26; i++) cin >> a[i];
  solve();
  return 0;
}
