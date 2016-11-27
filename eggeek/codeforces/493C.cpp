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
int n, m;
vector<ll> a, b;
set<ll> s;

ll calc(vector<ll>& v, ll d) {
  auto it = lower_bound(v.begin(), v.end(), d);
  if (it == v.end()) {
    return (int)v.size() * 2ll;
  } else {
    int l = (int)(it - v.begin());
    return (ll)(l * 2ll + (SZ(v)-l) * 3ll);
  }
}

void solve() {
  ll sa = -1, sb = -1;
  sort(ALL(a));
  sort(ALL(b));
  for (ll i: s) {
    ll ta = calc(a, i);
    ll tb = calc(b, i);
    if (sa == -1 || sa - sb < ta - tb) {
      sa = ta;
      sb = tb;
    }
  }
  cout << sa << ":" << sb << endl;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) cin >> a[i];
  cin >> m;
  b.resize(m);
  for (int i=0; i<m; i++) cin >> b[i];
  for (int i=0; i<n; i++) s.insert(a[i]);
  for (int i=0; i<m; i++) s.insert(b[i]);
  s.insert(0);
  s.insert(2e9+2ll);
  solve();
  return 0;
}
