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
#define N 55
const ll inf = 1e9 + 1ll;
ll n, r, x[N], y[N];
bool used[N];

void read() {
  cin >> n >> r;
  for (int i=0; i<n; i++) cin >> x[i] >> y[i];
}

vi find_zombies(ll X, ll Y) {
  ll x0 = X, x1 = X + r;
  ll y0 = Y, y1 = Y + r;
  vi res;
  for (int i=0; i<n; i++)
    if (!used[i] && x[i] >= x0 && x[i] <= x1 && y[i] >= y0 && y[i] <= y1) {
      used[i] = true;
      res.push_back(i);
    }
  return res;
}

int solve() {
  read();
  int ans = 0;
  memset(used, false, sizeof(used));
  set<ll> sx(x, x+n);
  set<ll> sy(y, y+n);
  for (ll i: sx) for (ll j: sy) {
    vi z0 = find_zombies(i, j);
    ans = max(ans, SZ(z0));
    for (ll u: sx) for (ll v: sy) {
      vi z1 = find_zombies(u, v);
      ans = max(ans, SZ(z0) + SZ(z1));
      for (int z: z1) used[z] = false;
    }
    for (int z: z0) used[z] = false;
  }
  assert(ans > 0);
  assert(ans <= n);
  return ans;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    int ans = solve();
    assert(ans > 0);
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
