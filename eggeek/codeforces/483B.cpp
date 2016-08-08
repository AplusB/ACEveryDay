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
ll c1, c2, x, y;

bool check(ll v) {
  ll a = v / y - v / (x * y); // only for c1
  ll b = v / x - v / (x * y); // only for c2
  ll c = v - v / x - v / y + v / (x * y); // for both c1 and c2
  if (a + c < c1) return false;
  ll use = max(0ll, c1 - a);
  if (b + c - use < c2) return false;
  return true;
}

void do_case() {
  ll l = 1, r = 2e9, best=-1;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      r = mid-1;
    } else l = mid+1;
  }
  cout << best << endl;
}

int main() {
  while (cin >> c1 >> c2 >> x >> y) do_case();
  return 0;
}
