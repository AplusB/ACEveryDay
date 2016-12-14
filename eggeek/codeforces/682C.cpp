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
int n, a[N];
bool vis[N];
struct edge {
  int to, c;
};
vector<edge> g[N];

void dfs(int cur, int pre, ll len) {
  vis[cur] = true;
  for (edge i: g[cur]) if (i.to != pre) {
    ll nxtL = max(0ll, len + (ll)i.c);
    if (nxtL <= (ll)a[i.to])
      dfs(i.to, cur, nxtL);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) scanf("%d", &a[i]);
  for (int i=2; i<=n; i++) {
    int v, c;
    scanf("%d%d", &v, &c);
    //printf("(%d, %d) %d\n", i, v, c);
    g[i].push_back(edge{v, c});
    g[v].push_back(edge{i, c});
  }
  memset(vis, false, sizeof(vis));
  dfs(1, 0, 0);
  int cnt = 0;
  for (int i=1; i<=n; i++) if (vis[i]) cnt++;
  printf("%d\n", n - cnt);
  return 0;
}
