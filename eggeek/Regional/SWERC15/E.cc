#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define N 2002
#define lowb(x) (x & (-x))

const ll mod = (1ll << 31) - 1;
int n, h[N];
ll dp[N][N];

class FenwickTree {
  private:
  ll t[N];
  int sz;
  public:

    void init(int size) {
      sz = size;
      for (int i=0; i<=sz; i++) t[i] = 0;
    }

    void add(int p, ll v) {
      while (p <= sz) {
        t[p] += v;
        p += lowb(p);
      }
    }

    ll prefix(int p) {
      ll ans = 0;
      while (p) {
        ans += t[p];
        p -= lowb(p);
      }
      return ans;
    }

    ll range(int l, int r) {
      if (l > r) return 0;
      return prefix(r) - prefix(l-1);
    }
} sum[N];

void read() {
  cin >> n;
  for (int i=0; i<=n; i++) cin >> h[i];
}

ll solve() {
  for (int i=1; i<=n; i++) sum[i].init(n+1);
  dp[1][h[0]] = 1;
  sum[1].add(h[0], 1);
  for (int i=2; i<=n; i++) {
    for (int j=1; j<=n+1; j++) if (j != h[i]) {
      if (h[i-1] == h[i]) { // hh
        if (j < h[i]) dp[i][j] += sum[i-1].range(1, h[i]-1);
        else if (j > h[i]) dp[i][j] += sum[i-1].range(h[i]+1, n+1);
      }

      // hl
      if (j < h[i] && h[i-1] < h[i]) {
        dp[i][j] += dp[i-1][h[i]];
      }
      if (j > h[i] && h[i-1] > h[i]) {
        dp[i][j] += dp[i-1][h[i]];
      }

      // lh
      if (j == h[i-1]) {
        if (j < h[i]) dp[i][j] += sum[i-1].range(h[i-1]+1, n+1);
        if (j > h[i]) dp[i][j] += sum[i-1].range(1, h[i-1]-1);
      }

      // ll
      if (j < h[i] && j < h[i-1]) {
        dp[i][j] += dp[i-1][j];
      }
      if (j > h[i] && j > h[i-1]) {
        dp[i][j] += dp[i-1][j];
      }
      if (dp[i][j] >= mod) dp[i][j] %= mod;
      //printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
    }
    for (int j=1; j<=n+1; j++) sum[i].add(j, dp[i][j]);
  }
  ll ans = 0;
  for (int i=1; i<=n+1; i++) if (i != h[n]) ans += dp[n][i];
  return ans % mod;
}

int main() {
  read();
  cout << solve() << endl;
  return 0;
}
