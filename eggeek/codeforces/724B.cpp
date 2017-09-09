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
#define N 22
int n, m, a[N][N], b[N][N];

int check(int x, int y) {
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++) b[i][j] = a[i][j];
  if (x != y) for (int i=1; i<=n; i++) swap(b[i][x], b[i][y]);

  for (int i=1; i<=n; i++) {
    bool flag = false;
    for (int j=1; j<=m && !flag; j++) if (b[i][j] != j) {
      for (int k=j+1; k<=m; k++) if (b[i][k] != k) {
        swap(b[i][j], b[i][k]);
        flag = true;
        break;
      }
    }
    for (int j=1; j<=m; j++) if (b[i][j] != j) return 0;
  }
  return 1;
}

int solve() {
  if (check(1, 1)) return 1;
  for (int i=1; i<=m; i++)
    for (int j=i+1; j<=m; j++)
      if (check(i, j)) {
        return 1;
      }
  return 0;
}

int main() {
  cin >> n >> m;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++) cin >> a[i][j];
  printf(solve()?"YES\n":"NO\n");
  return 0;
}
