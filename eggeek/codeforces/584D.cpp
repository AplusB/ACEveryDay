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
ll prim[N], n;
int cnt, dec[N];
bool vis[N];

void init() {
  for (int i=2; i<N; i++) {
    if (!vis[i]) prim[cnt++] = i;
    for (int j=0; j<cnt && prim[j] * (ll)i < N; j++) {
      vis[prim[j] * i] = true;
      if (i % prim[j] == 0) break;
    }
  }
}

bool is_prim(ll v) {
  for (int i=0; i<cnt; i++) {
    if (v % prim[i] == 0) return false;
    if (prim[i] * prim[i] > v) break;
  }
  return true;
}

void solve() {
  if (is_prim(n)) {
    cout << 1 << endl;
    cout << n << endl;
    return;
  }
  ll v;
  for (int i=n-2; i>=0; i--) if (is_prim(i)) {
    v = i;
    break;
  }
  if (n - v == 2) {
    cout << 2 << endl;
    cout << v << " " << 2 << endl;
    return;
  }
  ll rest = n - v;
  //printf("v:%lld rest:%lld\n", v, rest);
  for (int i=0; i<cnt && prim[i] < rest; i++) {
    for (int j=0; j<cnt && prim[j] + prim[i] <= rest; j++) if (prim[i] + prim[j] == rest) {
      cout << 3 << endl;
      cout << v << " " << prim[i] << " " << prim[j] << endl;
      return;
    }
  }
  assert(false);
}

int main() {
  init();
  cin >> n;
  solve();
  return 0;
}
