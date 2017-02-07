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
#define M 101
int n, m, a[N][M], k;
vector<pii> ans;

bool cmp(int u, int v) { return k?u < v: u > v; }

bool verify() {
  for (int i=1; i<=n; i++) {
    for (int j=1; j<m; j++) if (cmp(a[i][j], a[i][j+1])) return false;
  }
  if (SZ(ans) > m * (m-1) / 2) return false;
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) scanf("%d", &a[i][j]);
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      int swp = -1;
      for (int r=j+1; r<=m; r++) if (cmp(a[i][j], a[i][r])) {
        if (swp == -1) swp = r;
        else if (cmp(a[i][swp], a[i][r])) swp = r;
      }
      if (swp != -1) {
        if (k) ans.push_back({swp, j});
        else ans.push_back({j, swp});
        for (int x=1; x<=n; x++) if (cmp(a[x][j], a[x][swp])) swap(a[x][j], a[x][swp]);
      }
    }
  }
  printf("%d\n", SZ(ans));
  for (auto i: ans) printf("%d %d\n", i.first, i.second);
  assert(verify());
  return 0;
}
