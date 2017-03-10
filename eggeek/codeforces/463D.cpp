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
#define N 1010
int n, k, a[6][N], ord[6][N];
int f[N][N];

bool can_take(int cur, int prev) {
  if (prev == 0) return true;
  int p = a[1][prev], c = a[1][cur];
  for (int i=1; i<=k; i++) {
    if (ord[i][c] < ord[i][p]) return false;
  }
  return true;
}

int dfs(int cur, int prev) {
  if (f[cur][prev] != -1) return f[cur][prev];
  if (cur > n) return f[cur][prev] = 0;
  int res = 0;
  if (can_take(cur, prev)) {
    res = dfs(cur+1, cur) + 1;
  }
  res = max(res, dfs(cur+1, prev));
  return f[cur][prev] = res;
}

int main() {
  cin >> n >> k;
  for (int i=1; i<=k; i++) {
    for (int j=1; j<=n; j++) cin >> a[i][j];
    for (int j=1; j<=n; j++) ord[i][a[i][j]] = j;
  }
  memset(f, -1, sizeof(f));
  cout << dfs(1, 0) << endl;
  return 0;
}
