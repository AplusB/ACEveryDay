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
struct P {
  ll x, y;
};
P a, b;
vector<P> f;
int n;

ll dist(P u, P v) {
  ll dx = u.x - v.x;
  ll dy = u.y - v.y;
  return dx * dx + dy * dy;
}

ll solve(P r0, P r1) {
  ll ans = INF_LL;
  ll d0 = 0, d1 = 0;
  for (int i=0; i<n; i++) {
    d0 = dist(r0, f[i]);
    d1 = 0;
    for (int j=0; j<n; j++) if (j != i) {
      if (dist(r0, f[j]) <= d0) continue;
      d1 = max(d1, dist(r1, f[j]));
    }
    ans = min(ans, d0+d1);
  }
  return ans;
}

int main() {
  cin >> n;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  for (int i=0; i<n; i++) {
    P t;
    cin >> t.x >> t.y;
    f.push_back(t);
  }
  cout << min(solve(a, b), solve(b, a)) << endl;
  return 0;
}
