#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
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
#define N 19
int n, m, kk;
ll a[N],  dp[1<<N][N];
ll g[N][N];

void update(int mask, int to, ll v) {
  if (dp[mask][to] == -1) dp[mask][to] = v;
  else dp[mask][to] = max(dp[mask][to], v);
}

int cntb(int mask) {
  int res = 0;
  for (int i=0; i<n; i++) if (mask & (1<<i)) res++;
  return res;
}

ll solve() {
  memset(dp, -1, sizeof(dp));
  for (int i=0; i<n; i++) dp[1<<i][i] = a[i];
  for (int i=1; i<(1<<n); i++) {
    for (int j=0; j<n; j++) if ((i & (1<<j)) && dp[i][j] != -1) {
      for (int k=0; k<n; k++) if ((i & (1<<k)) == 0) {
        update(i | (1<<k), k, dp[i][j] + a[k] + g[j][k]);
      }
    }
  }
  ll res = -1;
  for (int i=0; i<(1<<n); i++) if (cntb(i) == m) {
    for (int j=0; j<n; j++) res = max(res, dp[i][j]);
  }
  return res;
}

int main() {
  cin >> n >> m >> kk;
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<kk; i++) {
    ll x, y, c;
    cin >> x >> y >> c;
    g[x-1][y-1] = c;
  }
  cout << solve() << endl;
  return 0;
}
