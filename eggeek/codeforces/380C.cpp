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
#define N 1000010

struct Node {
  int match, l, r;
};
Node t[N<<2];

int n, m;
char s[N];

Node combine(Node ls, Node rs) {
  Node res;
  res.match = ls.match + rs.match + min(ls.l, rs.r);
  res.l = ls.l - min(ls.l, rs.r) + rs.l;
  res.r = ls.r + rs.r - min(ls.l, rs.r);
  return res;
}

void build_tree(int l, int r, int id) {
  int mid = (l + r) >> 1;
  if (l == r) {
    t[id] = {0, s[l]=='(', s[l] == ')'};
    return;
  }
  build_tree(l, mid, id<<1);
  build_tree(mid+1, r, id<<1|1);
  t[id] = combine(t[id<<1], t[id<<1|1]);
}

Node query(int L, int R, int l, int r, int id) {
  int mid = (l + r) >> 1;
  if (L <= l && r <= R) return t[id];
  Node ls = Node{0, 0, 0};
  Node rs = Node{0, 0, 0};
  if (L <= mid) ls = query(L, R, l, mid, id<<1);
  if (R > mid) rs = query(L, R, mid+1, r, id<<1|1);
  return combine(ls, rs);
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  build_tree(0, n-1, 1);
  scanf("%d", &m);
  for (int i=1; i<=m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    Node res = query(l-1, r-1, 0, n-1, 1);
    printf("%d\n", res.match << 1);
  }
  return 0;
}
