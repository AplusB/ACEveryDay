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
ll n;
ll p[17];
ll dp[20][3];
vi d;
const int s = 1;

bool check(int num) {
  while (num) {
    int v = num % 10;
    if (v % 2) return false;
    num /= 10;
  }
  return true;
}

int solve_small() {
  int ans = (int)n;
  for (int i=0; i<20*n; i++) {
    if (check(i)) ans = min(ans, (int)abs(n-i));
  }
  return ans;
}

void init_d(ll num) {
  d.clear();
  while (num > 0) {
    d.push_back((int)(num % 10ll));
    num /= 10ll;
  }
}

void update(int i, int j, ll v) {
  if (dp[i][j + s] == -1 || dp[i][j + s] > v) {
    dp[i][j + s] = v;
  }
}

ll solve_large() {
  init_d(n);
  memset(dp, -1, sizeof(dp));
  dp[0][s] = 0;
  for (int i=0; i<(int)d.size(); i++) {
    for (int j=-1; j<=1; j++) if (dp[i][j + s] != -1) {

      if (d[i] + j < 0) {
        // 9 -> 0
        update(i+1, 0, dp[i][j+s] + (ll)p[i]);
        // 9 -> 8
        update(i+1, -1, dp[i][j+s] + (ll)p[i]);
        update(i+1, 1, dp[i][j+s] + 11ll * p[i]);
      }
      else if (d[i] + j == 10) { // d[i] = 9
        update(i+1, 1, dp[i][j+s]);
        update(i+1, 0, dp[i][j+s] + 2ll * p[i]);
        update(i+1, -1, dp[i][j+s] + 12ll * p[i]);
      }
      else if ((d[i] + j) % 2 == 0) {
        update(i+1, 0, dp[i][j+s]);
        update(i+1, 1, dp[i][j+s] + (ll)(10 - d[i] - j) * p[i]);
        update(i+1, -1, dp[i][j+s] + (ll)(d[i]+j+2) * p[i]);
      }
      else if ((d[i] + j) % 2 == 1 && (d[i]+j)<10) {
        update(i+1, 0, dp[i][j+s] + p[i]);
        update(i+1, -1, dp[i][j+s] + (ll)(d[i] + j + 2) * p[i]);
        update(i+1, 1, dp[i][j+s] + (ll)(10ll - d[i] - j) * p[i]);
      }
    }
  }
  ll ans = dp[(int)d.size()][s];
  return ans;
}

void do_case() {
  cin >> n;
  ll ans = solve_large();
  cout << ans << endl;
}

int main() {
  int cas;
  p[0] = 1;
  for (int i=1; i<=16; i++) {
    p[i] = p[i-1] * 10ll;
  }
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d: ", i);
    do_case();
  }
  return 0;
}
