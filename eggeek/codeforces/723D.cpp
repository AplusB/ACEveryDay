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
#define N 51
int n, m, k, num, vis[N][N];
char g[N][N];
vector<pii> sz;

int dfs(int r, int c, int ord) {
  int res = 1;
  bool flag = false;
  vis[r][c] = ord;
  if (r==0 || r==n-1 || c==0 || c==m-1) flag = true;
  for (int i=0; i<4; i++) {
    int nxtr = r + dx[i];
    int nxtc = c + dy[i];
    if (nxtr < 0 || nxtr >= n) continue;
    if (nxtc < 0 || nxtc >= m) continue;
    if (g[nxtr][nxtc] == '*') continue;
    if (vis[nxtr][nxtc]) continue;
    int v = dfs(nxtr, nxtc, ord);
    if (v == -1) flag = true;
    res += v;
  }
  if (flag) return -1;
  else return res;
}

void fill_up(int id) {
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) if (vis[i][j] == id) g[i][j] = '*';
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i=0; i<n; i++) scanf("%s", g[i]);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) if (g[i][j] == '.' && !vis[i][j]) {
      int cnt = dfs(i, j, ++num);
      if (cnt > 0) {
        sz.push_back({cnt, num});
      }
    }
  }
  sort(ALL(sz));
  int ans = 0;
  for (int i=0; i<SZ(sz)-k; i++) {
    fill_up(sz[i].second);
    ans += sz[i].first;
  }
  printf("%d\n", ans);
  for (int i=0; i<n; i++) printf("%s\n", g[i]);
  return 0;
}
