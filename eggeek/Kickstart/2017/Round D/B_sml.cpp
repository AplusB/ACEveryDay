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
#define N 100001
const ll offset = 1000 * 201;
ll n, k, A, B, c, d, e1, e2, f;
ll a[N], suma[N], b[N], sumb[N];
map<ll, ll> cntB, sum_cntB;

ll large_or_eq(ll v) {
  ll res = 0;
  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j++) {
      ll inc = 0;
      ll y = 0;
      ll x = suma[j] - suma[i-1];
      if (x == 0) {
        if (v <= 0) inc = n * (n-1) / 2;
      } else if (x > 0) {
        // xy >= v -> y >= v/x
        if (v * x < 0) {
          y = abs(v) / abs(x) * -1ll;
        } else {
          y = (abs(v) + abs(x) - 1) / abs(x);
        }
        if (y <= f*n) inc = sum_cntB[f*n] - sum_cntB[y-1];
      } else if (x < 0) {
        // xy >= v -> y <= v/x
        if (v * x < 0) {
          y = (abs(v) + abs(x) - 1) / abs(x) * -1ll;
        } else {
          y = abs(v) / abs(x);
        }
        if (y >= f*n) y = f*n;
        inc = sum_cntB[y];
      }
      res += inc;
    }
  }
  return res;
}

ll do_case() {
  cin >> n >> k >> A >> B >> c >> d >> e1 >> e2 >> f;
  a[1] = A, b[1] = B;
  ll x1 = A, y1 = B, r1 = 0, s1 = 0;
  for (int i=2; i<=n; i++) {
    ll nxtx = (c * x1 + d * y1 + e1) % f;
    ll nxty = (d * x1 + c * y1 + e2) % f;
    ll nxtr = (c * r1 + d * s1 + e1) % 2;
    ll nxts = (d * r1 + c * s1 + e2) % 2;
    x1 = nxtx, y1 = nxty, r1 = nxtr, s1 = nxts;
    a[i] = x1, b[i] = y1;
    if (r1 % 2) a[i] *= -1ll;
    if (s1 % 2) b[i] *= -1ll;
  }
  suma[0] = sumb[0] = 0;
  for (int i=1; i<=n; i++) {
    suma[i] = suma[i-1] + a[i];
    sumb[i] = sumb[i-1] + b[i];
  }

  cntB.clear();
  sum_cntB.clear();
  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j++) {
      ll vb = sumb[j] - sumb[i-1];
      cntB[vb] ++;
    }
  }
  sum_cntB[-f*n] = 0;
  assert(cntB[f*n] == 0);
  for (int i=-f*n+1; i<= f*n; i++) {
    sum_cntB[i] = sum_cntB[i-1] + cntB[i];
  }

  ll absv = f * n;
  ll lb = -1ll * absv * absv;
  ll ub = absv * absv;
  ll res = ub;

  while (lb <= ub) {
    ll mid = (lb + ub) >> 1;
    ll cnt = large_or_eq(mid);
    if (cnt >= k) {
      res = mid;
      lb = mid + 1;
    } else if (cnt < k) {
      ub = mid - 1;
    }
  }
  assert(large_or_eq(res) >= k && large_or_eq(res+1)<k);
  return res;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = do_case();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
