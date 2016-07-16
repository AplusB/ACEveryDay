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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 3000010
int n, m, cnt[N];
vll a, b;

class BIT {
public:
  vll t;
  int sz;
  void init(int size) {
    t.clear();
    sz = size;
    t.assign(sz, 0);
  }
  void insert(int pos, int v) {
    while (pos <= sz) {
      t[pos] +=v;
      pos += LOWB(pos);
    }
  }
  ll prefsum(int pos) {
    ll res = 0;
    assert(pos >= 0);
    while (pos) {
      res += t[pos];
      pos -= LOWB(pos);
    }
    return res;
  }
  ll get(int pos) {
    return sum(pos, pos);
  }
  ll sum(int l, int r) {
    if (l > r) return 0;
    return prefsum(r) - prefsum(l-1);
  }
};
BIT ans;

void read() {
  a.clear();
  for (int i=0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  scanf("%d", &m);
  b.clear();
  for (int i=0; i<m; i++) {
    int x;
    scanf("%d", &x);
    b.push_back(x);
  }
}

void do_case() {
  read();
  for (int i=0; i<n; i++) cnt[a[i]]++;
  UNIQUE(a);
  ans.init(N);
  for (ll i: a) {
    for (ll j=(ll)i*i; j<(ll)N; j+=(ll)i) {
      if (j == (ll)i*i) {
        ll val = (ll)cnt[i] * (ll)(cnt[i]-1);
        ans.insert(j, val);
      } else {
        ll val = (ll)cnt[i] * (ll)cnt[j / i] * 2l;
        ans.insert(j, val);
      }
    }
  }
  for (int i=0; i<m; i++) {
    ll res = (ll)n * (n-1) - ans.prefsum(b[i]-1);
    printf("%I64d\n", res);
  }
}

int main() {
  // freopen("test.in", "r", stdin);
  while (cin >> n) do_case();
  return 0;
}
