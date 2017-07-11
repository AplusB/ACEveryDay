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
int n, best;
vi e[N], a;
set<pii> g;

int dfs1(int cur, int p) {
  int res = 0;
  for (int i: e[cur]) if (i != p) {
    res += (g.find({i, cur}) != g.end());
    res += dfs1(i, cur);
  }
  return res;
}

void dfs(int cur, int cnt, int p) {
  if (cnt < best) {
    a.clear();
    a.push_back(cur);
    best = cnt;
  } else if (cnt == best) {
    a.push_back(cur);
  }
  for (int i: e[cur]) if (i != p) {
    int nxt;
    if (g.find({i, cur}) != g.end()) nxt = cnt - 1;
    else nxt = cnt + 1;
    dfs(i, nxt, cur);
  }
}

void solve() {
  int cnt = dfs1(1, -1);
  best = N;
  dfs(1, cnt, -1);
  printf("%d\n", best);
  sort(ALL(a));
  for (int i=0; i<SZ(a); i++) printf("%d%c", a[i], i+1<SZ(a)?' ': '\n');
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n-1; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    g.insert({s, t});
    e[s].push_back(t);
    e[t].push_back(s);
  }
  solve();
  return 0;
}
