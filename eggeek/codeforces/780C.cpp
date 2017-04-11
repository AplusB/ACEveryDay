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
vi e[N];
int n, c[N];

void dfs(int cur, int fa, int colpa) {
  int col = 1;
  for (int i: e[cur]) if (i != fa) {
    while (col == colpa || col == c[cur]) col++;
    c[i] = col++;
    dfs(i, cur, c[cur]);
  } }

int main() {
  cin >> n;
  for (int i=0; i<n-1; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  c[1] = 1;
  dfs(1, -1, -1);
  set<int> s;
  for (int i=1; i<=n; i++) s.insert(c[i]);
  printf("%d\n", SZ(s));
  for (int i=1; i<=n; i++) printf("%d%c", c[i], i==n?'\n':' ');
  return 0;
}
