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
#define N 303
int n, m;
ll c[N][N], w[N][N], dp[N][N];

void read() {
  scanf("%d%d", &n, &m);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) cin >> c[i][j];
    sort(c[i], c[i]+m);
  }
}

void update(ll& old, ll nxt) {
  if (nxt == -1) return;
  if (old == -1) old = nxt;
  old = min(old, nxt);
}

ll do_case() {
  read();
  memset(w, 0, sizeof(w));
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<n; i++) {
    for (int j=1; j<=m; j++) {
      w[i][j] = w[i][j-1] + c[i][j-1];
    }
    for (int j=1; j<=m; j++) w[i][j] += (ll)j*j;
  }
  dp[0][0] = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<=n; j++) if (dp[i][j] != -1) {
      for (int k=0; k+j-1<=n && k<=m; k++) {
        update(dp[i+1][k+j-1], dp[i][j] + w[i][k]);
      }
    }
  }
  assert(dp[n][0] != -1);
  return dp[n][0];
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = do_case();
    cout <<"Case #" << i << ": " << ans << endl;
  }
  return 0;
}
