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
struct Cyc {
  ll r, h;
};
int n, k;
vector<Cyc> cs;
ll dp[N][N];

bool cmp(Cyc u, Cyc v) {
  return u.r < v.r;
}

void update(ll &newv, ll up) {
  if (newv == -1ll || newv < up) newv = up;
}

bool vis[N];

ll dfs(int cur, int used) {
  if (used == k) {
    return (cs[cur-1].r * cs[cur-1].r);
  }
  if (cur == n) return 0;
  ll res = dfs(cur+1, used);
  ll tmp = dfs(cur+1, used+1);
  tmp += 2ll * cs[cur].h * cs[cur].r;
  if (tmp > res) {
    res = tmp;
    vis[cur] = true;
  }
  return res;
}
ll bf() {
  memset(vis, 0, sizeof(vis));
  return dfs(0, 0);
}

double solve() {
  cin >> n >> k;
  cs.resize(n);
  for (int i=0; i<n; i++) {
    cin >> cs[i].r >> cs[i].h;
  }
  sort(ALL(cs), cmp);
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<=n; i++) dp[i][0] = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<k; j++) if (dp[i][j] != -1) {
      update(dp[i+1][j+1], dp[i][j] + cs[i].h * cs[i].r);
      update(dp[i+1][j], dp[i][j]);
    }
  }
  ll ans = 0;
  for (int i=1; i<=n; i++) if (dp[i][k] != -1) {
      ans = max(ans, 2ll * dp[i][k] + cs[i-1].r * cs[i-1].r);
  }
  double res = (double)ans * acos(-1.0);
  /*
  ll naive = bf();
  if (naive != ans) {
    printf("naive: %lld ans: %lld\n", naive, ans);
    printf("n:%d k:%d\n", n, k);
    for (int i=0; i<n; i++) printf("%lld %lld %d\n", cs[i].r, cs[i].h, vis[i]);
    assert(false);
  }
  */
  return res;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    double ans = solve();
    printf("Case #%d: %.6lf\n", i, ans);
  }
  return 0;
}
