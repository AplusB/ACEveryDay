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
int n, col[N];
vi ans;
struct edge {
  int to, t;
};
vector<edge> g[N];

void dfs(int c, int pre) {
  bool flag = false;
  for (edge i: g[c]) if (i.to != pre) {
    if (i.t == 2 || col[i.to]) {
      dfs(i.to, c);
      flag = true;
    }
  }
  if (flag == false && c != 1) ans.push_back(c);
}

void color(int c, int pre) {
  for (edge i: g[c]) if (i.to != pre) {
    if (i.t == 2) col[i.to] = 1;
    color(i.to, c);
    col[c] |= col[i.to];
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n-1; i++) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    g[u].push_back(edge{v, t});
    g[v].push_back(edge{u, t});
  }
  memset(col, 0, sizeof(col));
  color(1, -1);
  dfs(1, -1);
  printf("%d\n", SZ(ans));
  for (int i: ans) printf("%d\n", i);
  return 0;
}
