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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
int n, l[27], nxt[27];
vi e[27];
bool fob[27][27], vis[27];
char ans[27][27];

void read() {
  scanf("%d", &n);
  char s[3];
  memset(fob, 0, sizeof(fob));
  for (int i=0; i<n; i++) {
    scanf("%s", s);
    fob[s[0]-'a'][s[1]-'a'] = true;
  }
}

void build_graph() {
  for (int i=0; i<26; i++) e[i].clear();
  for (int i=0; i<26; i++) {
    for (int j=0; j<26; j++) if (!fob[i][j]) e[i].push_back(j);
  }
}

int dfs(int c) {
  vis[c] = true;
  if (l[c] != 0) {
    vis[c] = false;
    return l[c];
  }
  int res = 1;
  for (int i: e[c]) {
    if (vis[i]) {
      nxt[c] = i;
      res = 39;
      break;
    }
    else {
      int tmp = dfs(i);
      if (tmp + 1 > res) {
        res = tmp + 1;
        nxt[c] = i;
      }
    }
  }
  vis[c] = false;
  res = min(res, 40);
  return l[c] = res;
}

void gen_path(int s, int len, vi& path) {
  path.clear();
  path.push_back(s);
  s = nxt[s];
  while (path.size() < len) {
    path.push_back(s);
    assert(s >= 0 && s < 26);
    s = nxt[s];
  }
}

void gen_map(vi& path, int k) {
  memset(ans, 0, sizeof(ans));
  for (int i=0; i<k; i++) {
    for (int j=0; j<k; j++) {
      assert(i+j<path.size());
      ans[i][j] = path[i+j] + 'a';
    }
  }
}

void do_case() {
  read();
  build_graph();
  memset(l, 0, sizeof(l));
  int maxl = 0, s = -1;
  for (int i=0; i<26; i++) {
    memset(vis, 0, sizeof(vis));
    int il = dfs(i);
    if (il > maxl) {
      maxl = il;
      s = i;
    }
  }
  vi path;
  gen_path(s, maxl, path);
  int k = (maxl + 1) / 2;
  gen_map(path, k);

  for (int i=0; i<k; i++) printf("%s\n", ans[i]);
}

int main() {
  int T;
  cin >> T;
  while (T--) do_case();
  return 0;
}
