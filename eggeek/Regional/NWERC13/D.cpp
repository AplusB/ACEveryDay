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
#define N 8
int n, k, r[N], c[N], t[N][N], cnt;

void dfs(int x, int y, int maxv) {
  if (x+1 <= c[y]) {
    int lb = max(t[x][y] + 1, t[x+1][y-1]);
    int ub = n - (c[y] - (x+1));
    for (int i=lb; i<ub; i++) {
      t[x+1][y] = i;
      dfs(x+1, y, max(maxv, i));
    }
  } else if (y+1 <= r[1]){
    int lb = t[1][y];
    int ub = n - (c[y+1] - 1);
    for (int i=lb; i<ub; i++) {
      t[1][y+1] = i;
      dfs(1, y+1, max(maxv, i));
    }
  } else {
    cnt += n - maxv;
    return;
  }
}

void solve() {
  memset(c, 0, sizeof(c));
  memset(r, 0, sizeof(r));
  memset(t, 0, sizeof(t));
  rep(i, 1, k+1) scanf("%d", &r[i]);
  scanf("%d", &n);
  rep(i, 1, 8) {
    rep(j, 1, 8) if (r[j]>=i) c[i] = j;
  }
  cnt = 0;
  dfs(1, 1, 0);
  printf("%d\n", cnt);
}

int main() {
  while (scanf("%d", &k) != EOF) solve();
  return 0;
}
