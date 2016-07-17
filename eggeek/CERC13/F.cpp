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
int dx[] = {-1, 1, -1, 1};
int dy[] = {1, 1, -1, -1};
/*-----------------------------------*/
#define N 11
char s[N][N];
vi e[100];
bool vis[100][100];

void read() {
  for (int i=0; i<10; i++) scanf("%s", s[i]);
}

bool in_bound(int r, int c) {
  if (r < 0 || r >= 10 || c < 0 || c >= 10) return false;
  return true;
}

int find_nxt(int r, int c, int d) {
  int r1 = r + dx[d];
  int c1 = c + dy[d];
  if (!in_bound(r1, c1)) return -1;
  if (s[r1][c1] != 'B') return -1;
  int r2 = r1 + dx[d];
  int c2 = c1 + dy[d];
  if (!in_bound(r2, c2)) return -1;
  if (s[r2][c2] == 'B' || s[r2][c2] == '.') return -1;
  return r2 * 10 + c2;
}

void build_graph() {
  for (int i=0; i<100; i++) e[i].clear();

  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) if (s[i][j] == '#' || s[i][j] == 'W'){
      int u = i * 10 + j;
      for (int k=0; k<4; k++) {
        int nxt = find_nxt(i, j, k);
        if (nxt != -1)
          e[u].push_back(nxt);
      }
    }
  }
}

int dfs(int id) {
  int res = 0;
  for (int i: e[id]) if (!vis[id][i]) {
    if (s[i/10][i%10] != '#') continue;
    vis[id][i] = true;
    vis[i][id] = true;
    s[id/10][id%10] = '#';
    s[i/10][i%10] = 'W';
    int tmp = dfs(i) + 1;
    s[id/10][id%10] = 'W';
    s[i/10][i%10] = '#';
    res = max(res, tmp);
    vis[id][i] = false;
    vis[i][id] = false;
  }
  return res;
}

void do_case() {
  read();
  build_graph();
  int ans = 0;
  for (int i=0; i<10; i++)
    for (int j=0; j<10; j++) if (s[i][j] == 'W') {
      memset(vis, 0, sizeof(vis));
      int tmp = dfs(i*10 + j);
      ans = max(ans, tmp);
    }
  printf("%d\n", ans);
}

int main() {
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
