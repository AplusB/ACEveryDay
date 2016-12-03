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
ll n, m;

bool check(ll h) {
  ll cnt2, cnt3, cnt6;
  cnt6 = h / 6;
  cnt2 = h / 2 - cnt6;
  cnt3 = h / 3 - cnt6;
  ll rest2, rest3;
  rest2 = max(0ll, n - cnt2);
  rest3 = max(0ll, m - cnt3);
  return rest2 + rest3 <= cnt6;
}

ll solve() {
  ll l = 0, r = 6ll * (n+m), best = r;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  return best;
}

int main() {
  cin >> n >> m;
  cout << solve() << endl;
  return 0;
}
