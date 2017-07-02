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
int n, k, d[N], dgr[N];
vi c[N];
vector<pii> e;

void add_edge(int u, int v) {
  dgr[u]++, dgr[v]++;
  e.push_back({u, v});
}

void solve() {
  if (SZ(c[0]) != 1) {
    printf("-1\n");
    return;
  }
  for (int i=0; i<n; i++) {
    int idx = 0;
    for (int j: c[i]) {
      while (idx < SZ(c[i+1]) && dgr[j] < k) {
        add_edge(j, c[i+1][idx]);
        idx++;
      }
    }
    if (idx != SZ(c[i+1])) {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n", SZ(e));
  for (pii i: e) printf("%d %d\n", i.first, i.second);
}

int main() {
  cin >> n >> k;
  for (int i=1; i<=n; i++) cin >> d[i];
  for (int i=1; i<=n; i++) {
    c[d[i]].push_back(i);
  }
  solve();
  return 0;
}
