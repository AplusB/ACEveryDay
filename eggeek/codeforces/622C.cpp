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
int n, m, a[N];
int big[N<<2], sml[N<<2];

void push_up(int id) {
  int ls = id << 1;
  int rs = id << 1 | 1;
  big[id] = a[big[ls]] > a[big[rs]]? big[ls]: big[rs];
  sml[id] = a[sml[ls]] < a[sml[rs]]? sml[ls]: sml[rs];
}

void build_tree(int l, int r, int id) {
  if (l == r) {
    big[id] = sml[id] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build_tree(l, mid, id << 1);
  build_tree(mid+1, r, id << 1 | 1);
  push_up(id);
}

pii query(int L, int R, int l, int r, int id) {
  int mid = (l + r) >> 1;
  if (L <= l && r <= R) {
    return {sml[id], big[id]};
  }
  pii resl = {-1, -1};
  pii resr = {-1, -1};
  if (L <= mid) resl = query(L, R, l, mid, id<<1);
  if (R > mid) resr = query(L, R, mid+1, r, id<<1|1);
  if (resl.first == -1) return resr;
  else if (resr.first == -1) return resl;
  else {
    int x = a[resl.first] < a[resr.first]? resl.first: resr.first;
    int y = a[resl.second] > a[resr.second]? resl.second: resr.second;
    return {x, y};
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  build_tree(1, n, 1);
  for (int i=0; i<m; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    pii p = query(l, r, 1, n, 1);
    if (a[p.first] == x && a[p.second] == x) printf("-1\n");
    else if (a[p.first] != x) printf("%d\n", p.first);
    else printf("%d\n", p.second);
  }
  return 0;
}
