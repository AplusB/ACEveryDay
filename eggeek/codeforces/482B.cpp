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
class SegmentTree{
  int n, id;
  vi t, lz;

  public:
  SegmentTree(int n, int id) {
    this->n = n + 1;
    this->id = id;
    t.resize(this->n << 2);
    lz.resize(this->n << 2);
    fill(t.begin(), t.end(), 0);
    fill(lz.begin(), lz.end(), 0);
  }

  void set(int l, int r, int v) {
    //printf("set(%d, %d) v:%d, id:%d\n", l, r, v, id);
    _set(1, n, 1, l, r, v);
  }

  int query(int l, int r) {
    int res = _query(1, n, 1, l, r);
    //printf("qeury(%d, %d) id:%d = %d\n", l, r, id, res);
    return res;
  }

  private:
  void _set(int l, int r, int id, int L, int R, int v) {
    int mid = (l + r) >> 1;
    if (l == r) {
      t[id] = r - l + 1;
      return;
    }
    if (L <= l && r <= R) {
      lz[id] = v;
      t[id] = r - l + 1;
      return;
    }
    pushdown(id, l, r);
    if (L <= mid) _set(l, mid, id << 1, L, R, v);
    if (R > mid) _set(mid+1, r, id<<1|1, L, R, v);
    pushup(id);
  }

  int _query(int l, int r, int id, int L, int R) {
    if (L <= l && r <= R) return t[id];
    int mid = (l + r) >> 1;
    int res = 0;
    pushdown(id, l, r);
    if (L <= mid) res += _query(l, mid, id << 1, L, R);
    if (R > mid) res += _query(mid+1, r, id<<1|1, L, R);
    pushup(id);
    //printf("sub query(%d, %d): %d\n", l, r, res);
    return res;
  }

  void pushdown(int id, int l, int r) {
    if (lz[id]) {
      int mid = (l + r) >> 1;
      t[id<<1] = mid - l + 1;
      t[id<<1|1] = r - mid;
      lz[id<<1] = lz[id];
      lz[id<<1|1] = lz[id];
      lz[id] = 0;
    }
  }

  void pushup(int id) {
    t[id] = t[id<<1] + t[id<<1|1];
  }

};

int n, m, l[N], r[N], a[N], q[N], sum[30][N], b[N][30];
vector<SegmentTree> ts;
vector<vector<pii>> lrs;

void solve() {
  int cntb = 30;
  for (int i=0; i<cntb; i++) ts.push_back(SegmentTree(n, i));
  for (int i=1; i<=m; i++) {
    for (int j=0; j<cntb; j++) if (q[i] & (1 << j)) {
      ts[j].set(l[i], r[i], 1);
    }
  }
  for (int i=1; i<=m; i++) {
    for (int j=0; j<cntb; j++) if ((q[i] & (1<<j)) == 0) {
      int cnt = ts[j].query(l[i], r[i]);
      assert(cnt <= r[i] - l[i] + 1);
      if (cnt == r[i] - l[i] + 1) {
        printf("NO\n");
        return;
      }
    }
  }
  fill(a+1, a+1+n, 0);
  for (int i=1; i<=n; i++) {
    for (int j=0; j<cntb; j++) {
      if (ts[j].query(i, i)) a[i] += 1<<j;
    }
  }
  printf("YES\n");
  for (int i=1; i<=n; i++) printf("%d%c", a[i], i==n?'\n': ' ');
}

void solve2() {
  int cntb = 30;
  lrs.resize(cntb);
  for (int i=1; i<=m; i++) {
    for (int j=0; j<cntb; j++) if (q[i] & (1 << j)) {
      lrs[j].push_back({l[i], r[i]});
    }
  }
  for (int j=0; j<cntb; j++) {
    sort(lrs[j].begin(), lrs[j].end());
  }
  memset(sum, 0, sizeof(sum));
  memset(b, 0, sizeof(b));
  for (int j=0; j<cntb; j++) {
    int idx = 1;
    for (pii i: lrs[j]) {
      while (idx < i.first) idx++;
      while (idx <= i.second) {
        b[idx][j]++;
        assert(b[idx][j] == 1);
        a[idx++] += 1 << j;
      }
    }
  }

  for (int j=0; j<cntb; j++) {
    for (int i=1; i<=n; i++) sum[j][i] = sum[j][i-1] + ((a[i] & (1<<j)) > 0);
  }
  for (int i=1; i<=m; i++) {
    for (int j=0; j<cntb; j++) if ((q[i] & (1 << j)) == 0)  {
      int cnt = sum[j][r[i]] - sum[j][l[i]-1];
      if (cnt == r[i] - l[i] + 1) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
  for (int i=1; i<=n; i++) printf("%d%c", a[i], i==n?'\n': ' ');
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=m; i++) scanf("%d%d%d", &l[i], &r[i], &q[i]);
  //solve();
  solve2();
  return 0;
}
