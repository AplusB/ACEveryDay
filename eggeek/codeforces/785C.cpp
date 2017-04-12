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

ll solve() {
  if (n <= m) return n;
  ll x = max(0ll, (ll)sqrt(2.0*(n-m)) - 2ll);
  while (true) {
    // x + m days
    // x + m days night
    ll rest = n - x - m;
    if (rest <= 0) return min(x + m, n);
    // x + m + 1 day
    rest = n - x * (x + 1ll) / 2ll;
    if (rest <= x+m+1) return x+m+1;
    x++;
  }
  assert(false);
  return -1;
}

int main() {
  cin >> n >> m;
  cout << solve() << endl;
  return 0;
}
