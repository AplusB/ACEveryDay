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
ll n, l, r;
map<ll, ll> h;

ll countLen(ll v) {
  if (v <= 1) return 1;
  ll l0 = countLen(v / 2ll);
  ll res = 2ll * l0 + 1l;
  h[v] = res;
  return res;
}

inline bool isIntersect(ll l1, ll r1, ll l2, ll r2) {
  if (r1 < l2 || l1 > r2) return false;
  else return true;
}

ll countOne(ll v, ll pos, const ll L, const ll R) {
  ll res = 0;
  if (pos > R) return 0;
  if (v > 1) {
    ll len = h[v / 2ll];
    ll mid = pos + len;
    // range: [pos, pos + 2 * len]
    if (mid >= L && mid <= R) res += (v % 2ll);
    if (isIntersect(pos, mid-1, L, R)) res += countOne(v/2ll, pos, L, R);
    if (isIntersect(mid+1, mid+len, L, R)) res += countOne(v/2ll, mid+1ll, L, R);
  } else {
    if (pos >= L && pos <= R) res += v;
  }
  return res;
}

int main() {
  cin >> n >> l >> r;
  countLen(n);
  h[1] = 1;
  h[0] = 1;
  cout << countOne(n, 1, l, r) << endl;
  return 0;
}
