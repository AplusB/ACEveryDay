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

int solve(vi& d, vi& h, int n, int m) {
  int res = h[0] + d[0] - 1;

  for (int i=1; i<m; i++) {
    res = max(res, h[1]);
    int dur = d[i] - d[i-1];
    int dif = h[i] - h[i-1];
    if (abs(dif) > dur) return -1;
    res = max(res, (dur + h[i] + h[i-1]) / 2);
  }
  res = max(res, h[m-1] + n - d[m-1]);
  return res;
}

int main() {
  int n, m;
  vi d, h;
  cin >> n >> m;
  d.resize(m);
  h.resize(m);
  for (int i=0; i<m; i++) cin >> d[i] >> h[i];
  int maxH = solve(d, h, n, m);
  if (maxH == -1) printf("IMPOSSIBLE\n");
  else printf("%d\n", maxH);
  return 0;
}
