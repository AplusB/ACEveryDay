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
int res[N][N];

void solve(int n, int k) {
  memset(res, -1, sizeof(res));
  for (int i=1; i<=n; i++) {
    int cur = 0;
    for (int j=1; j<=n; j++) if (res[i][j] == 1) cur++;
    for (int j=1; j<=n && cur < k; j++) if (j != i && res[i][j] == -1) {
      res[i][j] = 1;
      res[j][i] = 0;
      cur++;
    }
    if (cur < k) {
      printf("-1\n");
      return;
    }
  }
  vector<pii> ans;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) if (res[i][j] == 1) {
      ans.push_back({i, j});
    }
  }
  printf("%d\n", SZ(ans));
  for (pii i: ans) printf("%d %d\n", i.first, i.second);
}

int main() {
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}
