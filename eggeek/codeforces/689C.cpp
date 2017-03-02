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
ll m;

ll calc(ll n) {
  ll K = (ll)cbrt(n);
  ll k = K + 1;
  if (k * k * k <= n) K++;
  assert(K <= 200001);
  ll cnt = 0ll;
  for (ll i=2; i<=K; i++) {
    cnt += n / (i * i * i);
  }
  return cnt;
}

ll solve() {
  ll l = 1ll, r = (ll)8e15, best = -1;
  while (l <= r) {
    ll mid = (l + r) >> 1ll;
    ll cnt = calc(mid);
    if (cnt < m)
      l = mid + 1ll;
    else
      r = mid - 1ll;
    if (cnt == m) best = mid;
  }
  return best;
}

int main() {
  cin >> m;
  cout << solve() << endl;
  return 0;
}
