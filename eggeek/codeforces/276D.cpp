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
ll l, r;
ll dp[65][2][2];
int len;

bool check(int m, int bc, int bl, int br) {
  if ((m & 2) == 0 && bc < bl) return false;
  if ((m & 1) == 0 && bc > br) return false;
  return true;
 }

int new_mask(int m, int bc, int bl, int br) {
  int res = m;
  if ((m & 2) == 0 && bc > bl) res |= 1;
  if ((m & 1) == 0 && bc < br) res |= 2;
  return res;
}

ll dfs(int pos, int m1, int m2) {
  if (pos == 0) return dp[pos][m1][m2] = 0;
  if (dp[pos][m1][m2] != -1) return dp[pos][m1][m2];
  ll res = 0;
  int bl = (l >> (pos-1)) & 1;
  int br = (r >> (pos-1)) & 1;
  ll tmp;
  for (int i=0; i<2; i++) if (check(m1, i, bl, br)) {
    for (int j=0; j<2; j++) if (check(m2, j, bl, br)) {
      int newm1 = new_mask(m1, i, bl, br);
      int newm2 = new_mask(m2, j, bl, br);
      tmp = dfs(pos-1, newm1, newm2) + ((ll)(i ^ j) << (pos - 1));
      res = max(res, tmp);
    }
  }
  return dp[pos][m1][m2] = res;
}

ll bf() {
  ll res = 0;
  for (ll i=l; i<=r; i++) {
    for (ll j=i; j<=r; j++) {
      res = max(res, i ^ j);
    }
  }
  return res;
}

int main() {
  cin >> l >> r;
  memset(dp, -1, sizeof(dp));
  ll tmp = r;
  while (tmp) {
    tmp >>= 1;
    len++;
  }
  // ll res = dfs(len, 0, 0);
  // assert(res == bf());
  cout << dfs(len, 0, 0) << endl;
  return 0;
}
