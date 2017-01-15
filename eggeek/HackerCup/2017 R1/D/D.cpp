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
#define N 2002
const ll mod = 1e9 + 7ll;
ll n, m, r[N], a[N], b[2*N], totR;

ll inv(ll val) {
  ll t = mod - 2;
  ll res = 1ll;
  while (t) {
    if (t & 1) {
      res = res * val;
      if (res >= mod) res %= mod;
    }
    t >>= 1;
    val = val * val;
    if (val >= mod) val %= mod;
  }
  return res;
}

ll C(ll x, ll y) { // x > y
  assert(y < N);
  ll idx = x - m + 1 + totR;
  ll up = b[idx];
  ll down = a[y];
  return up * inv(down) % mod;
}

ll f(ll p, ll b) {
  if (p < 0) return 0;
  assert(b < N);
  ll res = C(p+b-1, b-1);
  //printf("f(%lld, %lld) = %lld\n", p, b, res);
  return res;
}

ll solve() {
  scanf("%lld%lld", &n, &m);
  for (int i=1; i<=n; i++) scanf("%lld", &r[i]);
  totR = 0;
  for (int i=1; i<=n; i++) totR += r[i];
  a[0] = 1;
  if (n == 1) return m;
  totR *= 2ll;

  for (int i=1; i<=4000; i++) {
    b[i] = 1;
    ll x = m - 1ll - totR + i;
    for (int j=0; j<n; j++) {
      b[i] = b[i] * (x - (ll)j);
      if (b[i] >= mod) b[i] %= mod;
    }
  }

  ll ans = 0;
  ll cnt = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) if (j != i) {
      cnt++;
      ans += a[n-2] * f(m - 1ll - totR + r[i] + r[j], n+1);
      if (ans >= mod) ans %= mod;
    }
  }
  return ans;
}

void init() {
  a[0] = 1;
  for (int i=1; i<N; i++) a[i] = a[i-1] * (ll)i % mod;
}

int main() {
  int cas;
  init();
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = solve();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
