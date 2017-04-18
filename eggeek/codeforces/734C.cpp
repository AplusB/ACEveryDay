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
#define N 200010
ll n, m, k, x, s;
ll a[N], b[N], c[N], d[N];

ll bs(ll rest) {
  ll l = 0, r = k-1, best = -1;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (d[mid] <= rest) {
      best = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return best;
}

ll solve() {
  ll res = n * x;
  // use 1
  for (int i=0; i<m; i++) if (b[i] <= s) {
    res = min(res, n * a[i]);
    ll rest = s - b[i];
    ll idx = bs(rest);
    if (idx == -1) continue;
    ll cur = max(0ll, n - c[idx]) * a[i];
    res = min(res, cur);
    //printf("i:%d, idx:%lld, cur:%lld\n", i, idx, cur);
  }
  // dont use 1
  ll idx = bs(s);
  //printf("idx: %lld\n", idx);
  if (idx != -1) {
    ll cur = max(0ll, n - c[idx]) * x;
    res = min(res, cur);
  }
  return res;
}

int main() {
  cin >> n >> m >>k >> x >> s;
  for (int i=0; i<m; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> b[i];
  for (int i=0; i<k; i++) cin >> c[i];
  for (int i=0; i<k; i++) cin >> d[i];
  cout << solve() << endl;
  return 0;
}
