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
class BIT {
  public:
  vi t;
  int size;

  void init(int sz) {
    size = sz;
    t.assign(sz + 1, 0);
  }

  void add(int p, int v) {
    for (;p <= size; p += LOWB(p)) t[p] += v;
  }

  int getVal(int p) {
    int res = 0;
    for (; p; p -= LOWB(p)) res += t[p];
    return res;
  }
} f;
int n, q;
vi a;

int main() {
  cin >> n >> q;
  a.resize(n + 1);
  f.init(n+1);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    f.add(l, 1);
    f.add(r+1, -1);
  }
  vi v(n+1);
  for (int i=1; i<=n; i++) v[i] = f.getVal(i);
  sort(ALL(v));
  sort(ALL(a));
  ll res = 0;
  for (int i=1; i<=n; i++) res += (ll)a[i] * (ll)v[i];
  cout << res << endl;
  return 0;
}
