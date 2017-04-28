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
#define N 5050
struct Edge {
  int v, ti;
};

struct Status {
  int id, cnt, ti;
};
int n, m, t;
int dp[N][N];
int g[N][N];
vector<Edge> e[N];

struct cmp {
  bool operator() (Status u, Status v) {
    return u.ti > v.ti;
  }
};

priority_queue<Status, vector<Status>, cmp> q;
void solve() {
  memset(dp, -1, sizeof(dp));
  dp[1][1] = 0;
  q.push(Status{1, 1, 0});
  while (!q.empty()) {
    Status cur = q.top(); q.pop();
    int id = cur.id;
    int ti = cur.ti;
    int cnt = cur.cnt;
    //printf("id:%d ti:%d cnt:%d\n", id, ti, cnt);
    if (ti > dp[id][cnt]) continue;
    assert(ti == dp[id][cnt]);
    for (Edge i: e[id]) {
      int v = i.v;
      if (i.ti + ti > t) continue;
      if (dp[v][cnt+1] == -1 || dp[v][cnt+1] > i.ti + ti) {
        dp[v][cnt+1] = i.ti + ti;
        q.push(Status{v, cnt+1, ti+i.ti});
      }
    }
  }
  int res = 0;
  for (int i=1; i<=n; i++) if (dp[n][i] != -1) res = max(res, i);
  int res_tmp = res;
  vi vis;
  int cur = n;
  vis.push_back(n);
  while (cur != 1) {
    for (int i=1; i<=n; i++)
      if (g[i][cur] != -1 && dp[i][res-1] != -1 && dp[cur][res] - g[i][cur] == dp[i][res-1]) {
        vis.push_back(i);
        cur = i;
        res--;
        break;
      }
  }
  assert(res_tmp == SZ(vis));
  reverse(ALL(vis));
  printf("%d\n", SZ(vis));
  for (int i=0; i<SZ(vis); i++) printf("%d%c", vis[i], i+1<SZ(vis)?' ': '\n');
}

int main() {
  cin >> n >> m >> t;
  memset(g, -1, sizeof(g));
  for (int i=1; i<=m; i++) {
    int u, v, ti;
    cin >> u >> v >> ti;
    e[u].push_back(Edge{v, ti});
    g[u][v] = ti;
  }
  solve();
  return 0;
}
