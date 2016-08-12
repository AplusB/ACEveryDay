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
#define N 1000010
int n;
ll a[N], f[N], t[N];

ll solve() {
  if (n == 1) return 0;
  f[0] = 0;
  f[1] = abs(a[1] - a[0]);
  for (int i=2; i<n; i++) {
    ll s1 = a[i-1] - a[i-2];
    ll s2 = a[i] - a[i-1];
    if (s1 * s2 > 0ll) {
      f[i] = f[i-1] + abs(s2);
    } else {
      f[i] = max(f[i-1], f[i-2] + abs(s2));
    }
  }
  t[n-1] = 0;
  t[n-2] = abs(a[n-1] - a[n-2]);
  for (int i=n-3; i>=0; i--) {
    ll s1 = a[i+1] - a[i+2];
    ll s2 = a[i] - a[i+1];
    if (s1 * s2 > 0ll) {
      t[i] = t[i+1] + abs(s2);
    } else {
      t[i] = max(t[i+1], t[i+2] + abs(s2));
    }
  }
  ll res = t[0];
  for (int i=0; i+1<n; i++) {
    res = max(res, f[i] + t[i+1]);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = (ll)x;
  }
  ll ans = solve();
  cout << ans << endl;
  return 0;
}
