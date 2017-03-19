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
#define N 100010
ll n, x, y;

bool check(ll t, ll tot) {
  ll cnt = t / x + t / y;
  return cnt < tot;
}

ll bs(ll tot) {
  ll l=0, r=x*y, best=0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid, tot)) {
      best = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return best;
}

int find(ll tot) {
  ll t0 = tot / (x + y);
  tot -= t0 * (x + y);
  if (tot == 0) return 0;
  ll t1 = bs(tot);
  ll after_shoot = tot - t1/x - t1/y;
  //printf("t1: %lld, tot:%lld, after:%lld\n", t1, tot, after_shoot);
  assert(after_shoot > 0);
  ll diffx = (y - t1 % y);
  ll diffy = (x - t1 % x);
  //printf("diffx:%lld, diffy:%lld\n", diffx, diffy);
  if (diffx < diffy) return -1;
  else if (diffx == diffy) return 0;
  else return 1;
}

void solve() {
  int cnt = 0;
  ll sum = 0;
  for (int i=1; i<=n; i++) {
    ll a;
    cin >> a;
    sum += a;
    int f = find(a);
    if (f == -1) printf("Vanya\n");
    else if (f == 0) {
      printf("Both\n");
      cnt++;
    }
    else printf("Vova\n");
  }
}

int main() {
  cin >> n >> x >> y;
  solve();
  return 0;
}
