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
ll x[N], y[N], z[N], r[N], minX, minY, minZ, maxX, maxY, maxZ;
int n;

bool contain(ll lx, ll ly, ll lz, ll len, int i) {
  if (lx <= x[i] - r[i] && x[i] + r[i] <= lx + len &&
      ly <= y[i] - r[i] && y[i] + r[i] <= ly + len &&
      lz <= z[i] - r[i] && z[i] + r[i] <= lz + len) return true;
  return false;
}

bool check(ll len) {
  for (int i=1; i<=n; i++) {
    for (int mask=0; mask<8; mask++) {
      ll lx, ly, lz;
      lx = (mask & 1) ? minX: maxX - len;
      ly = (mask & 2) ? minY: maxY - len;
      lz = (mask & 4) ? z[i] - r[i]: z[i] + r[i] - len;

      ll lbx, lby, lbz, ubx, uby, ubz;
      lbx = lby = lbz = ubx = uby = ubz = INF_LL;
      //printf("loc(%lld, %lld, %lld), len: %lld\n", lx, ly, lz, len);
      for (int j=1; j<=n; j++) if (!contain(lx, ly, lz, len, j)) {
        lbx = lbx == INF_LL? x[j] - r[j]: min(lbx, x[j] - r[j]);
        ubx = ubx == INF_LL? x[j] + r[j]: max(ubx, x[j] + r[j]);
        lby = lby == INF_LL? y[j] - r[j]: min(lby, y[j] - r[j]);
        uby = uby == INF_LL? y[j] + r[j]: max(uby, y[j] + r[j]);
        lbz = lbz == INF_LL? z[j] - r[j]: min(lbz, z[j] - r[j]);
        ubz = ubz == INF_LL? z[j] + r[j]: max(ubz, z[j] + r[j]);
        //printf("not include: (%lld, %lld, %lld) r:%lld, space(%lld, %lld, %lld) to (%lld, %lld, %lld)\n", x[j], y[j], z[j], r[j], lbx, lby, lbz, ubx, uby, ubz);
      }
      if (ubx - lbx <= len &&
          uby - lby <= len &&
          ubz - lbz <= len) {
        //printf("space(%lld, %lld, %lld) to (%lld, %lld, %lld)\n", lbx, lby, lbz, ubx, uby, ubz);
        return true;
      }
    }
  }
  return false;
}

ll bsearch() {
  ll l=0, r=(ll)4e10, best=(ll)4e10;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      r = mid - 1ll;
    } else l = mid + 1ll;
  }
  return best;
}

ll solve() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> x[i] >> y[i] >> z[i] >> r[i];
  minX = minY = minZ = maxX = maxY = maxZ = INF_LL;
  for (int i=1; i<=n; i++) {
    minX = minX == INF_LL? x[i] - r[i]: min(minX, x[i] - r[i]);
    minY = minY == INF_LL? y[i] - r[i]: min(minY, y[i] - r[i]);
    minZ = minZ == INF_LL? z[i] - r[i]: min(minZ, z[i] - r[i]);
    maxX = maxX == INF_LL? x[i] + r[i]: max(maxX, x[i] + r[i]);
    maxY = maxY == INF_LL? y[i] + r[i]: max(maxY, y[i] + r[i]);
    maxZ = maxZ == INF_LL? z[i] + r[i]: max(maxZ, z[i] + r[i]);
  }
  ll res = bsearch();
  return res;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    ll ans = solve();
    printf("Case #%d: %lld\n", i, ans);
  }
  return 0;
}
