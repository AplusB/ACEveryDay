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
ll s, x1, x2, t1, t2, p, d;

ll solve() {
  ll res1 = abs(x1 - x2) * t2;
  ll res2 = 0;
  if (x1 < x2) {
    if (p <= x1) {
      if (d == 1) res2 = t1 * (x2 - p);
      else res2 = t1 * (p + x2);
    } else {
      if (d == 1) res2 = t1 * (s - p + s + x2);
      else res2 = t1 * (p + x2);
    }
  } else if (x1 > x2) {
    if (p >= x1) {
      if (d == -1) res2 = t1 * (p - x2);
      else res2 = t1 * (s - p + s - x2);
    } else {
      if (d == -1) res2 = t1 * (p + s + s - x2);
      else res2 = t1 * (s - p + s - x2);
    }
  }
  return min(res1, res2);
}

int main() {
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  cout << solve() << endl;
  return 0;
}
