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
#define N 300010
class BIT {
  public:
  vi t;
  int size;
  void init(int sz) {
    t.assign(sz+1, 0);
    size = sz;
  }
  void add(int p, int v) {
    while (p <= size) { t[p] += v; p += LOWB(p); }
  }
  int sum(int p) {
    int res = 0;
    while (p) { res += t[p]; p -= LOWB(p); }
    return res;
  }
  int rsum(int l, int r) {
    int res = sum(r);
    if (l-1 >= 1) res -= sum(l-1);
    return res;
  }
};
BIT f;
int n, m;
string s;

int get_ans(int val) {
  int res = 0;
  while (val > 1) {
    res += val / 2;
    val = (val + 1) / 2;
  }
  return res;
}

int bsl(int l, int r) {
  int best = r, R = r;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (f.rsum(mid, R) < R - mid + 1) {
      l = mid + 1;
    } else {
      best = mid;
      r = mid - 1;
    }
  }
  return best;
}

int bsr(int l, int r) {
  int best = l, L = l;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (f.rsum(L, mid) < mid - L + 1) {
      r = mid - 1;
    } else {
      best = mid;
      l = mid + 1;
    }
  }
  return best;
}

int main() {
  cin >> n >> m >> s;
  f.init(n);
  for (int i=1; i<=n; i++) if (s[i-1] == '.') f.add(i, 1);
  int ans = 0;
  for (int i=1; i<=n; i++) if (s[i-1] == '.') {
    if (i==n  || s[i] != '.') {
      int lb = bsl(1, i);
      ans += get_ans(f.rsum(lb, i));
    }
  }
  while (m--) {
    int x;
    char c[3];
    scanf("%d%s", &x, c);
    if (s[x-1] == '.' && c[0] == '.') printf("%d\n", ans);
    else if (s[x-1] != '.' && c[0] != '.') printf("%d\n", ans);
    else if (s[x-1] == '.' && c[0] != '.') {
      int lb = bsl(1, x);
      int ub = bsr(x, n);
      ans -= get_ans(ub - lb + 1);
      ans += get_ans(x - lb);
      ans += get_ans(ub - x);
      f.add(x, -1);
      s[x-1] = c[0];
      printf("%d\n", ans);
    }
    else if (s[x-1] != '.' && c[0] == '.') {
      int lb = bsl(1, x-1);
      int ub = bsr(x+1, n);
      if (s[lb-1] != '.') lb = x;
      if (s[ub-1] != '.') ub = x;
      ans -= get_ans(x-lb);
      ans -= get_ans(ub-x);
      ans += get_ans(ub - lb + 1);
      f.add(x, 1);
      s[x-1] = c[0];
      printf("%d\n", ans);
    }
  }
  return 0;
}
