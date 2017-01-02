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
int n, m, w, a[N], h[N];

void insert(int pos, int v) {
  for (int i=pos; i<=n; i += LOWB(i)) h[i] += v;
}

int getV(int pos) {
  int res = 0;
  for (int i=pos; i>0; i -= LOWB(i)) res += h[i];
  return res;
}

bool check(int minH) {
  memset(h, 0, sizeof(h));
  int tot = 0;
  for (int i=1; i<=n; i++) {
    int v = getV(i);
    if (a[i] + v < minH) {
      int need = minH - a[i] - v;
      insert(i, need);
      insert(min(i+w, n+1), -need);
      tot += need;
    }
    if (tot > m) return false;
  }
  return true;
}

int solve() {
  int l = 0, r = 1e9 + m, best = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      best = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  return best;
}

int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  int ans = solve();
  printf("%d\n", ans);
  return 0;
}
