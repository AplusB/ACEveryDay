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
#define N 505
int n, a[N], f[N][N];

int dfs(int l, int r) {
  if (f[l][r] != -1) return f[l][r];
  if (l == r) return f[l][r] = 1;
  if (l+1 == r && a[l] == a[r]) return f[l][r] = 1;
  int res = N;
  if (a[l] == a[r]) {
    res = dfs(l+1, r-1);
  }
  for (int k=l; k<r; k++) {
    int tmp = dfs(l, k) + dfs(k+1, r);
    res = min(res, tmp);
  }
  return f[l][r] = res;
}

int main() {
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  memset(f, -1, sizeof(f));
  cout << dfs(1, n) << endl;
  return 0;
}
