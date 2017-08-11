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
#define N 200020
int n, sz;
ll sum[N<<2], lz[N<<2];

void push_down(int L, int R, int rt) {
  int ls = rt<<1, rs = rt<<1|1, mid = (L+R)>>1;
  if (lz[rt]) {
    sum[ls] += (ll)(mid-L+1)*lz[rt];
    sum[rs] += (ll)(R-mid)*lz[rt];
    lz[ls] += lz[rt];
    lz[rs] += lz[rt];
    lz[rt] = 0;
  }
}

void push_up(int rt) {
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

ll query(int l, int r, int L, int R, int rt) {
  if (l > r) return 0;
  ll res = 0;
  if (l <= L && R <= r) return sum[rt];
  push_down(L, R, rt);
  int mid = (L + R) >> 1;
  if (l <= mid) res += query(l, r, L, mid, rt<<1);
  if (r > mid) res += query(l, r, mid+1, R, rt<<1|1);
  push_up(rt);
  return res;
}

void print_ave() {
    ll tot = query(1, sz, 1, N, 1);
    printf("%.6lf\n", (double)tot / sz);
}

void update(int l, int r, ll v, int L, int R, int rt) {
  int mid = (L + R) >> 1;
  if (l <= L && R <= r) {
    sum[rt] += v * (ll)(R-L+1);
    lz[rt] += v;
    return;
  }
  push_down(L, R, rt);
  if (l <= mid) update(l, r, v, L, mid, rt<<1);
  if (r > mid) update(l, r, v, mid+1, R, rt<<1|1);
  push_up(rt);
}

int main() {
  scanf("%d", &n);
  sz = 1;
  for (int i=0; i<n; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, a;
      scanf("%d%d", &a, &x);
      update(1, a, x, 1, N, 1);
      print_ave();
    } else if (t == 2) {
      int k;
      scanf("%d", &k);
      sz++;
      update(sz, sz, k, 1, N, 1);
      print_ave();
    } else {
      if (sz > 1) {
        ll v = query(sz, sz, 1, N,1);
        update(sz, sz, -v, 1, N, 1);
        sz--;
      }
      print_ave();
    }
  }
  return 0;
}
