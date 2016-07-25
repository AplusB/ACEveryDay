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
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 200001
const ll INF = 1e15;
map<pll, ll> c;
map<ll, vector<pll>> rcd;
set<pll> ans;
ll m;

ll bsearch2(ll l, ll r) {
  while (l <= r) {
    ll mid = (l + r) >> 1l;
    ll tmp = mid * (mid-1l) / 2l;
    if (tmp == m) return mid;
    else if (tmp > m) r = mid-1l;
    else l = mid + 1l;
  }
  return -1;
}

ll bsearch3(ll l, ll r) {
  while (l <= r) {
    ll mid = (l + r) >> 1l;
    ll tmp = mid * (mid -1l) * (mid-2l) / 6;
    if (tmp == m) return mid;
    else if (tmp > m) r = mid - 1l;
    else l = mid + 1l;
  }
  return -1;
}

void print_ans() {
  bool flag = false;
  printf("%d\n", (int)ans.size());
  for (auto i: ans) {
    if (flag) cout << ' ';
    else flag = true;
    cout << "(" << i.first << "," << i.second << ")";
  }
  cout << endl;
}

void insert(ll n, ll k) {
  ans.insert(make_pair(n, k));
  ans.insert(make_pair(n, n-k));
}

void do_case() {
  cin >> m;
  ans.clear();
  auto it = rcd.lower_bound(m);
  if (it != rcd.end() && it->first == m) {
    assert(it->first == m);
    for (auto i: it->second)
      insert(i.first, i.second);
  }
  insert(m, 1);
  ll n = bsearch2(1l, 1e8);
  if (n != -1) insert(n, 2l);
  n = bsearch3(1l, N);
  if (n != -1) insert(n, 3l);
  print_ans();
}

void update(ll n, ll k, ll val) {
  c[make_pair(n, k)] = val;
  rcd[val].push_back(make_pair(n, k));
}

ll get_val(ll n, ll k) {
  k = min(k, n-k);
  pll p = make_pair(n, k);
  if (c.find(p) != c.end()) return c[p];
  else return -1l;
}

void init_c() {
  update(0, 0, 1);
  for (int i=1; i<N; i++) {
    update(i, 0, 1);
    for (int j=1; j<=i/2; j++) {
      ll a = get_val(i-1, j-1);
      ll b = get_val(i-1, j);
      if (a == -1 || b == -1) break;
      if (a + b <= INF)
        update(i, j, a + b);
      else break;
    }
  }
  //printf("%d\n", (int)c.size());
}

int main() {
  init_c();
  int cas;
  cin >> cas;
  while (cas--) do_case();
  return 0;
}
