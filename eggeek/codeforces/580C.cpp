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
#define N 100001
vi e[N];
int cat[N], m, n;

int dfs(int cur, int pre, int cnt) {
  int res = 0;
  bool isleaf = true;
  for (int i: e[cur]) if (i != pre) {
    isleaf = false;
    int nxt_cnt = cat[i]?cnt + 1: 0;
    if (nxt_cnt <= m)
      res += dfs(i, cur, nxt_cnt);
  }
  return isleaf?1: res;
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++) cin >> cat[i];
  for (int i=1; i<n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int ans = dfs(1, -1, cat[1]);
  cout << ans << endl;
  return 0;
}
